/*******************************************************************************
 * Copyright (c) 2018, 2022 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at http://eclipse.org/legal/epl-2.0
 * or the Apache License, Version 2.0 which accompanies this distribution
 * and is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License, v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception [1] and GNU General Public
 * License, version 2 with the OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/

#include <stdint.h>
#include <string.h>

#include "ras/Debug.hpp"

#include "codegen/ARM64ConditionCode.hpp"
#include "codegen/ARM64HelperCallSnippet.hpp"
#include "codegen/ARM64Instruction.hpp"
#include "codegen/ARM64OutOfLineCodeSection.hpp"
#include "codegen/CodeGenerator.hpp"
#include "codegen/ConstantDataSnippet.hpp"
#include "codegen/GCRegisterMap.hpp"
#include "codegen/InstOpCode.hpp"
#include "codegen/MemoryReference.hpp"
#include "codegen/RealRegister.hpp"
#include "codegen/Register.hpp"
#include "codegen/RegisterConstants.hpp"
#include "codegen/RegisterDependency.hpp"
#include "codegen/RegisterDependencyStruct.hpp"
#include "codegen/Relocation.hpp"
#include "codegen/Snippet.hpp"
#include "env/IO.hpp"
#include "il/Block.hpp"
#include "runtime/CodeCacheManager.hpp"

#ifdef J9_PROJECT_SPECIFIC
#include "aarch64/codegen/CallSnippet.hpp"
#include "aarch64/codegen/StackCheckFailureSnippet.hpp"

namespace TR { class ARM64ForceRecompilationSnippet; }
#endif

static const char *ARM64ConditionNames[] =
   {
   "eq",
   "ne",
   "cs",
   "cc",
   "mi",
   "pl",
   "vs",
   "vc",
   "hi",
   "ls",
   "ge",
   "lt",
   "gt",
   "le",
   "al",
   "nv"
   };

static const char *ARM64ShiftCodeNames[] =
   {
   "lsl",
   "lsr",
   "asr",
   "???"
   };

static const char *ARM64ExtendCodeNames[] =
   {
   "uxtb",
   "uxth",
   "uxtw",
   "uxtx",
   "sxtb",
   "sxth",
   "sxtw",
   "sxtx"
   };

static const char *opCodeToNameMap[] =
   {
   "assocreg",
   "bad",
   "dd",
   "fence",
   "label",
   "proc",
   "retn",
   "vgnop",
   "cbzw",
   "cbnzw",
   "cbzx",
   "cbnzx",
   "tbz",
   "tbnz",
   "b_cond",
   "brkarm64",
   "dsb",
   "dmb",
   "br",
   "blr",
   "ret",
   "b",
   "bl",
   "stxrb",
   "stlxrb",
   "ldxrb",
   "ldaxrb",
   "stlrb",
   "ldarb",
   "stxrh",
   "stlxrh",
   "ldxrh",
   "ldaxrh",
   "stlrh",
   "ldarh",
   "stxrw",
   "stlxrw",
   "stxpw",
   "stlxpw",
   "ldxrw",
   "ldaxrw",
   "ldxpw",
   "ldaxpw",
   "stlrw",
   "ldarw",
   "stxrx",
   "stlxrx",
   "stxpx",
   "stlxpx",
   "ldxrx",
   "ldaxrx",
   "ldxpx",
   "ldaxpx",
   "stlrx",
   "ldarx",
   "ldrw",
   "vldrs",
   "ldrx",
   "vldrd",
   "ldrsw",
   "vldrq",
   "prfm",
   "stnpw",
   "ldnpw",
   "vstnps",
   "vldnps",
   "vstnpd",
   "vldnpd",
   "stnpx",
   "ldnpx",
   "vstnpq",
   "vldnpq",
   "stppostw",
   "ldppostw",
   "vstpposts",
   "vldpposts",
   "ldpswpost",
   "vstppostd",
   "vldppostd",
   "stppostx",
   "ldppostx",
   "vstppostq",
   "vldppostq",
   "stpoffw",
   "ldpoffw",
   "vstpoffs",
   "vldpoffs",
   "ldpswoff",
   "vstpoffd",
   "vldpoffd",
   "stpoffx",
   "ldpoffx",
   "vstpoffq",
   "vldpoffq",
   "stpprew",
   "ldpprew",
   "vstppres",
   "vldppres",
   "ldpswpre",
   "vstppred",
   "vldppred",
   "stpprex",
   "ldpprex",
   "vstppreq",
   "vldppreq",
   "sturb",
   "ldurb",
   "ldursbx",
   "ldursbw",
   "vsturb",
   "vldurb",
   "vsturq",
   "vldurq",
   "sturh",
   "ldurh",
   "ldurshx",
   "ldurshw",
   "vsturh",
   "vldurh",
   "sturw",
   "ldurw",
   "ldursw",
   "vsturs",
   "vldurs",
   "sturx",
   "ldurx",
   "prfum",
   "vsturd",
   "vldurd",
   "strbpost",
   "ldrbpost",
   "ldrsbpostx",
   "ldrsbpostw",
   "vstrpostb",
   "vldrpostb",
   "vstrpostq",
   "vldrpostq",
   "strhpost",
   "ldrhpost",
   "ldrshpostx",
   "ldrshpostw",
   "vstrposth",
   "vldrposth",
   "strpostw",
   "ldrpostw",
   "ldrswpost",
   "vstrposts",
   "vldrposts",
   "strpostx",
   "ldrpostx",
   "vstrpostd",
   "vldrpostd",
   "sttrb",
   "ldtrb",
   "ldtrsbx",
   "ldtrsbw",
   "sttrh",
   "ldtrh",
   "ldtrshx",
   "ldtrshw",
   "sttrw",
   "ldtrw",
   "ldtrsw",
   "sttrx",
   "ldtrx",
   "strbpre",
   "ldrbpre",
   "ldrsbprex",
   "ldrsbprew",
   "vstrpreb",
   "vldrpreb",
   "vstrpreq",
   "vldrpreq",
   "strhpre",
   "ldrhpre",
   "ldrshprex",
   "ldrshprew",
   "vstrpreh",
   "vldrpreh",
   "strprew",
   "ldrprew",
   "ldrswpre",
   "vstrpres",
   "vldrpres",
   "strprex",
   "ldrprex",
   "vstrpred",
   "vldrpred",
   "strboff",
   "ldrboff",
   "ldrsboffx",
   "ldrsboffw",
   "vstroffb",
   "vldroffb",
   "vstroffq",
   "vldroffq",
   "strhoff",
   "ldrhoff",
   "ldrshoffx",
   "ldrshoffw",
   "vstroffh",
   "vldroffh",
   "stroffw",
   "ldroffw",
   "ldrswoff",
   "vstroffs",
   "vldroffs",
   "stroffx",
   "ldroffx",
   "vstroffd",
   "vldroffd",
   "prfmoff",
   "strbimm",
   "ldrbimm",
   "ldrsbimmx",
   "ldrsbimmw",
   "vstrimmb",
   "vldrimmb",
   "vstrimmq",
   "vldrimmq",
   "strhimm",
   "ldrhimm",
   "ldrshimmx",
   "ldrshimmw",
   "vstrimmh",
   "vldrimmh",
   "strimmw",
   "ldrimmw",
   "ldrswimm",
   "vstrimms",
   "vldrimms",
   "strimmx",
   "ldrimmx",
   "vstrimmd",
   "vldrimmd",
   "prfmimm",
   "ldaddx",
   "ldaddax",
   "ldaddlx",
   "ldaddalx",
   "ldaddw",
   "ldaddaw",
   "ldaddlw",
   "ldaddalw",
   "ldaddb",
   "ldaddab",
   "ldaddlb",
   "ldaddalb",
   "ldaddh",
   "ldaddah",
   "ldaddlh",
   "ldaddalh",
   "ldclrx",
   "ldclrax",
   "ldclrlx",
   "ldclralx",
   "ldclrw",
   "ldclraw",
   "ldclrlw",
   "ldclralw",
   "ldclrb",
   "ldclrab",
   "ldclrlb",
   "ldclralb",
   "ldclrh",
   "ldclrah",
   "ldclrlh",
   "ldclralh",
   "ldeorx",
   "ldeorax",
   "ldeorlx",
   "ldeoralx",
   "ldeorw",
   "ldeoraw",
   "ldeorlw",
   "ldeoralw",
   "ldeorb",
   "ldeorab",
   "ldeorlb",
   "ldeoralb",
   "ldeorh",
   "ldeorah",
   "ldeorlh",
   "ldeoralh",
   "ldsetx",
   "ldsetax",
   "ldsetlx",
   "ldsetalx",
   "ldsetw",
   "ldsetaw",
   "ldsetlw",
   "ldsetalw",
   "ldsetb",
   "ldsetab",
   "ldsetlb",
   "ldsetalb",
   "ldseth",
   "ldsetah",
   "ldsetlh",
   "ldsetalh",
   "ldsmaxx",
   "ldsmaxax",
   "ldsmaxlx",
   "ldsmaxalx",
   "ldsmaxw",
   "ldsmaxaw",
   "ldsmaxlw",
   "ldsmaxalw",
   "ldsmaxb",
   "ldsmaxab",
   "ldsmaxlb",
   "ldsmaxalb",
   "ldsmaxh",
   "ldsmaxah",
   "ldsmaxlh",
   "ldsmaxalh",
   "ldsminx",
   "ldsminax",
   "ldsminlx",
   "ldsminalx",
   "ldsminw",
   "ldsminaw",
   "ldsminlw",
   "ldsminalw",
   "ldsminb",
   "ldsminab",
   "ldsminlb",
   "ldsminalb",
   "ldsminh",
   "ldsminah",
   "ldsminlh",
   "ldsminalh",
   "ldumaxx",
   "ldumaxax",
   "ldumaxlx",
   "ldumaxalx",
   "ldumaxw",
   "ldumaxaw",
   "ldumaxlw",
   "ldumaxalw",
   "ldumaxb",
   "ldumaxab",
   "ldumaxlb",
   "ldumaxalb",
   "ldumaxh",
   "ldumaxah",
   "ldumaxlh",
   "ldumaxalh",
   "lduminx",
   "lduminax",
   "lduminlx",
   "lduminalx",
   "lduminw",
   "lduminaw",
   "lduminlw",
   "lduminalw",
   "lduminb",
   "lduminab",
   "lduminlb",
   "lduminalb",
   "lduminh",
   "lduminah",
   "lduminlh",
   "lduminalh",
   "staddx",
   "staddlx",
   "staddw",
   "staddlw",
   "staddb",
   "staddlb",
   "staddh",
   "staddlh",
   "stclrx",
   "stclrlx",
   "stclrw",
   "stclrlw",
   "stclrb",
   "stclrlb",
   "stclrh",
   "stclrlh",
   "steorx",
   "steorlx",
   "steorw",
   "steorlw",
   "steorb",
   "steorlb",
   "steorh",
   "steorlh",
   "stsetx",
   "stsetlx",
   "stsetw",
   "stsetlw",
   "stsetb",
   "stsetlb",
   "stseth",
   "stsetlh",
   "stsmaxx",
   "stsmaxlx",
   "stsmaxw",
   "stsmaxlw",
   "stsmaxb",
   "stsmaxlb",
   "stsmaxh",
   "stsmaxlh",
   "stsminx",
   "stsminlx",
   "stsminw",
   "stsminlw",
   "stsminb",
   "stsminlb",
   "stsminh",
   "stsminlh",
   "stumaxx",
   "stumaxlx",
   "stumaxw",
   "stumaxlw",
   "stumaxb",
   "stumaxlb",
   "stumaxh",
   "stumaxlh",
   "stuminx",
   "stuminlx",
   "stuminw",
   "stuminlw",
   "stuminb",
   "stuminlb",
   "stuminh",
   "stuminlh",
   "swpx",
   "swpax",
   "swplx",
   "swpalx",
   "swpw",
   "swpaw",
   "swplw",
   "swpalw",
   "swpb",
   "swpab",
   "swplb",
   "swpalb",
   "swph",
   "swpah",
   "swplh",
   "swpalh",
   "casx",
   "casax",
   "caslx",
   "casalx",
   "casw",
   "casaw",
   "caslw",
   "casalw",
   "casb",
   "casab",
   "caslb",
   "casalb",
   "cash",
   "casah",
   "caslh",
   "casalh",
   "adr",
   "adrp",
   "addimmw",
   "addsimmw",
   "subimmw",
   "subsimmw",
   "addimmx",
   "addsimmx",
   "subimmx",
   "subsimmx",
   "andimmw",
   "orrimmw",
   "eorimmw",
   "andsimmw",
   "andimmx",
   "orrimmx",
   "eorimmx",
   "andsimmx",
   "movnw",
   "movzw",
   "movkw",
   "movnx",
   "movzx",
   "movkx",
   "sbfmw",
   "bfmw",
   "ubfmw",
   "sbfmx",
   "bfmx",
   "ubfmx",
   "extrw",
   "extrx",
   "andw",
   "bicw",
   "orrw",
   "ornw",
   "eorw",
   "eonw",
   "andsw",
   "bicsw",
   "andx",
   "bicx",
   "orrx",
   "ornx",
   "eorx",
   "eonx",
   "andsx",
   "bicsx",
   "addw",
   "addsw",
   "subw",
   "subsw",
   "addx",
   "addsx",
   "subx",
   "subsx",
   "addextw",
   "addsextw",
   "subextw",
   "subsextw",
   "addextx",
   "addsextx",
   "subextx",
   "subsextx",
   "adcw",
   "adcsw",
   "sbcw",
   "sbcsw",
   "adcx",
   "adcsx",
   "sbcx",
   "sbcsx",
   "ccmnw",
   "ccmnx",
   "ccmpw",
   "ccmpx",
   "ccmnimmw",
   "ccmnimmx",
   "ccmpimmw",
   "ccmpimmx",
   "cselw",
   "csincw",
   "csinvw",
   "csnegw",
   "cselx",
   "csincx",
   "csinvx",
   "csnegx",
   "maddw",
   "maddx",
   "smaddl",
   "umaddl",
   "msubw",
   "msubx",
   "smsubl",
   "umsubl",
   "smulh",
   "umulh",
   "fmaddd",
   "fmadds",
   "crc32x",
   "crc32cx",
   "crc32b",
   "crc32cb",
   "crc32h",
   "crc32ch",
   "crc32w",
   "crc32cw",
   "udivw",
   "udivx",
   "sdivw",
   "sdivx",
   "lslvw",
   "lslvx",
   "lsrvw",
   "lsrvx",
   "asrvw",
   "asrvx",
   "rorvw",
   "rorvx",
   "rbitw",
   "rbitx",
   "clzw",
   "clzx",
   "clsw",
   "clsx",
   "revw",
   "revx",
   "rev16w",
   "rev16x",
   "rev32",
   "fmov_stow",
   "fmov_wtos",
   "fmov_dtox",
   "fmov_xtod",
   "fcvt_stod",
   "fcvt_dtos",
   "fcvtzs_stow",
   "fcvtzs_dtow",
   "fcvtzs_stox",
   "fcvtzs_dtox",
   "scvtf_wtos",
   "scvtf_wtod",
   "scvtf_xtos",
   "scvtf_xtod",
   "fmovimms",
   "fmovimmd",
   "movi0s",
   "movi0d",
   "fcmps",
   "fcmps_zero",
   "fcmpd",
   "fcmpd_zero",
   "fcsels",
   "fcseld",
   "fmovs",
   "fmovd",
   "fabss",
   "fabsd",
   "fnegs",
   "fnegd",
   "fsqrts",
   "fsqrtd",
   "fadds",
   "faddd",
   "fsubs",
   "fsubd",
   "fmuls",
   "fmuld",
   "fdivs",
   "fdivd",
   "fmaxs",
   "fmaxd",
   "fmins",
   "fmind",
   "vorr2d",
   "vadd16b",
   "vadd8h",
   "vadd4s",
   "vadd2d",
   "vfadd4s",
   "vfadd2d",
   "vsub16b",
   "vsub8h",
   "vsub4s",
   "vsub2d",
   "vfsub4s",
   "vfsub2d",
   "vmul16b",
   "vmul8h",
   "vmul4s",
   "vfmul4s",
   "vfmul2d",
   "vfdiv4s",
   "vfdiv2d",
   "vand16b",
   "vorr16b",
   "veor16b",
   "vneg16b",
   "vneg8h",
   "vneg4s",
   "vneg2d",
   "vfneg4s",
   "vfneg2d",
   "vnot16b",
   "vdup16b",
   "vdup8h",
   "vdup4s",
   "vdup2d",
   "vfdup4s",
   "vfdup2d",
   "nop",
   };

const char *
TR_Debug::getOpCodeName(TR::InstOpCode *opCode)
   {
   return opCodeToNameMap[opCode->getMnemonic()];
   }

void
TR_Debug::printMemoryReferenceComment(TR::FILE *pOutFile, TR::MemoryReference *mr)
   {
   if (pOutFile == NULL)
      return;

   TR::Symbol *symbol = mr->getSymbolReference()->getSymbol();
   if (symbol == NULL && mr->getSymbolReference()->getOffset() == 0)
      return;

   trfprintf(pOutFile, "\t\t# SymRef");
   print(pOutFile, mr->getSymbolReference());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::Instruction *instr)
   {
   if (pOutFile == NULL)
      return;

   switch (instr->getKind())
      {
      case OMR::Instruction::IsImm:
         print(pOutFile, (TR::ARM64ImmInstruction *)instr);
         break;
      case OMR::Instruction::IsSynchronization:
         print(pOutFile, (TR::ARM64ImmInstruction *)instr); // printing handled by superclass
         break;
      case OMR::Instruction::IsException:
         print(pOutFile, (TR::ARM64ImmInstruction *)instr); // printing handled by superclass
         break;
      case OMR::Instruction::IsRelocatableImm:
         print(pOutFile, (TR::ARM64RelocatableImmInstruction *)instr);
         break;
      case OMR::Instruction::IsImmSym:
         print(pOutFile, (TR::ARM64ImmSymInstruction *)instr);
         break;
      case OMR::Instruction::IsLabel:
         print(pOutFile, (TR::ARM64LabelInstruction *)instr);
         break;
      case OMR::Instruction::IsConditionalBranch:
         print(pOutFile, (TR::ARM64ConditionalBranchInstruction *)instr);
         break;
      case OMR::Instruction::IsCompareBranch:
         print(pOutFile, (TR::ARM64CompareBranchInstruction *)instr);
         break;
      case OMR::Instruction::IsTestBitBranch:
         print(pOutFile, (TR::ARM64TestBitBranchInstruction *)instr);
         break;
#ifdef J9_PROJECT_SPECIFIC
      case OMR::Instruction::IsVirtualGuardNOP:
         print(pOutFile, (TR::ARM64VirtualGuardNOPInstruction *)instr);
         break;
#endif
      case OMR::Instruction::IsRegBranch:
         print(pOutFile, (TR::ARM64RegBranchInstruction *)instr);
         break;
      case OMR::Instruction::IsAdmin:
         print(pOutFile, (TR::ARM64AdminInstruction *)instr);
         break;
      case OMR::Instruction::IsTrg1:
         print(pOutFile, (TR::ARM64Trg1Instruction *)instr);
         break;
      case OMR::Instruction::IsTrg1Cond:
         print(pOutFile, (TR::ARM64Trg1CondInstruction *)instr);
         break;
      case OMR::Instruction::IsTrg1Imm:
         print(pOutFile, (TR::ARM64Trg1ImmInstruction *)instr);
         break;
      case OMR::Instruction::IsTrg1ImmSym:
         print(pOutFile, (TR::ARM64Trg1ImmSymInstruction *)instr);
         break;
      case OMR::Instruction::IsTrg1ZeroSrc1:
         print(pOutFile, (TR::ARM64Trg1ZeroSrc1Instruction *)instr);
         break;
      case OMR::Instruction::IsTrg1ZeroImm:
         print(pOutFile, (TR::ARM64Trg1ZeroImmInstruction *)instr);
         break;
      case OMR::Instruction::IsTrg1Src1:
         print(pOutFile, (TR::ARM64Trg1Src1Instruction *)instr);
         break;
      case OMR::Instruction::IsTrg1Src1Imm:
         print(pOutFile, (TR::ARM64Trg1Src1ImmInstruction *)instr);
         break;
      case OMR::Instruction::IsTrg1Src2:
         print(pOutFile, (TR::ARM64Trg1Src2Instruction *)instr);
         break;
      case OMR::Instruction::IsCondTrg1Src2:
         print(pOutFile, (TR::ARM64CondTrg1Src2Instruction *)instr);
         break;
      case OMR::Instruction::IsTrg1Src2Shifted:
         print(pOutFile, (TR::ARM64Trg1Src2ShiftedInstruction *)instr);
         break;
      case OMR::Instruction::IsTrg1Src2Extended:
         print(pOutFile, (TR::ARM64Trg1Src2ExtendedInstruction *)instr);
         break;
      case OMR::Instruction::IsTrg1Src2Zero:
         print(pOutFile, (TR::ARM64Trg1Src2ZeroInstruction *)instr);
         break;
      case OMR::Instruction::IsTrg1Src3:
         print(pOutFile, (TR::ARM64Trg1Src3Instruction *)instr);
         break;
      case OMR::Instruction::IsTrg1Mem:
         print(pOutFile, (TR::ARM64Trg1MemInstruction *)instr);
         break;
      case OMR::Instruction::IsMem:
         print(pOutFile, (TR::ARM64MemInstruction *)instr);
         break;
      case OMR::Instruction::IsMemImm:
         print(pOutFile, (TR::ARM64MemImmInstruction *)instr);
         break;
      case OMR::Instruction::IsMemSrc1:
         print(pOutFile, (TR::ARM64MemSrc1Instruction *)instr);
         break;
      case OMR::Instruction::IsMemSrc2:
         print(pOutFile, (TR::ARM64MemSrc2Instruction *)instr);
         break;
      case OMR::Instruction::IsTrg1MemSrc1:
         print(pOutFile, (TR::ARM64Trg1MemSrc1Instruction *)instr);
         break;
      case OMR::Instruction::IsSrc1:
         print(pOutFile, (TR::ARM64Src1Instruction *)instr);
         break;
      case OMR::Instruction::IsZeroSrc1Imm:
         print(pOutFile, (TR::ARM64ZeroSrc1ImmInstruction *)instr);
         break;
      case OMR::Instruction::IsSrc2:
         print(pOutFile, (TR::ARM64Src2Instruction *)instr);
         break;
      case OMR::Instruction::IsZeroSrc2:
         print(pOutFile, (TR::ARM64ZeroSrc2Instruction *)instr);
         break;
      default:
         TR_ASSERT(false, "unexpected instruction kind");
            // fall through
      case OMR::Instruction::IsNotExtended:
         {
         printPrefix(pOutFile, instr);
         trfprintf(pOutFile, "%s", getOpCodeName(&instr->getOpCode()));
         trfflush(_comp->getOutFile());
         }
      }
   }

void
TR_Debug::printInstructionComment(TR::FILE *pOutFile, int32_t tabStops, TR::Instruction *instr)
   {
   while (tabStops-- > 0)
      trfprintf(pOutFile, "\t");

   dumpInstructionComments(pOutFile, instr);
   }

void
TR_Debug::printPrefix(TR::FILE *pOutFile, TR::Instruction *instr)
   {
   if (pOutFile == NULL)
      return;

   printPrefix(pOutFile, instr, instr->getBinaryEncoding(), instr->getBinaryLength());
   TR::Node *node = instr->getNode();
   trfprintf(pOutFile, "%d \t", node ? node->getByteCodeIndex() : 0);
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64ImmInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t0x%08x", getOpCodeName(&instr->getOpCode()), instr->getSourceImmediate());
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64RelocatableImmInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t" POINTER_PRINTF_FORMAT "\t; %s",
             getOpCodeName(&instr->getOpCode()), instr->getSourceImmediate(),
             TR::ExternalRelocation::getName(instr->getReloKind()));
   TR::SymbolReference *sr = instr->getSymbolReference();
   if (sr)
      trfprintf(pOutFile, " \"%s\"", getName(sr));
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64ImmSymInstruction *instr)
   {
   printPrefix(pOutFile, instr);

   TR::Symbol *target = instr->getSymbolReference()->getSymbol();
   const char *name = target ? getName(instr->getSymbolReference()) : 0;
   if (name)
      trfprintf(pOutFile, "%s \t" POINTER_PRINTF_FORMAT "\t\t; Direct Call \"%s\"", getOpCodeName(&instr->getOpCode()), instr->getAddrImmediate(), name);
   else
      trfprintf(pOutFile, "%s \t" POINTER_PRINTF_FORMAT, getOpCodeName(&instr->getOpCode()), instr->getAddrImmediate());

   printInstructionComment(pOutFile, 1, instr);

   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64LabelInstruction *instr)
   {
   printPrefix(pOutFile, instr);

   TR::LabelSymbol *label = instr->getLabelSymbol();
   TR::Snippet *snippet = label ? label->getSnippet() : NULL;
   if (instr->getOpCodeValue() == TR::InstOpCode::label)
      {
      print(pOutFile, label);
      trfprintf(pOutFile, ":");
      if (label->isStartInternalControlFlow())
         trfprintf(pOutFile, "\t; (Start of internal control flow)");
      else if (label->isEndInternalControlFlow())
         trfprintf(pOutFile, "\t; (End of internal control flow)");
      }
   else
      {
      trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
      print(pOutFile, label);
      if (snippet)
         {
         trfprintf(pOutFile, " (%s)", getName(snippet));
         }
      }
   printInstructionComment(pOutFile, 1, instr);
   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());
   trfflush(_comp->getOutFile());
   }

#ifdef J9_PROJECT_SPECIFIC
void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64VirtualGuardNOPInstruction * instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s Site:" POINTER_PRINTF_FORMAT ", ", getOpCodeName(&instr->getOpCode()), instr->getSite());
   print(pOutFile, instr->getLabelSymbol());
   printInstructionComment(pOutFile, 1, instr);
   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());
   trfflush(pOutFile);
   }
#endif

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64ConditionalBranchInstruction *instr)
   {
   printPrefix(pOutFile, instr);

   TR::LabelSymbol *label = instr->getLabelSymbol();
   TR::Snippet *snippet = label ? label->getSnippet() : NULL;
   TR_ASSERT(instr->getOpCodeValue() == TR::InstOpCode::b_cond, "Unsupported instruction for conditional branch");
   trfprintf(pOutFile, "b.%s \t", ARM64ConditionNames[instr->getConditionCode()]);
   print(pOutFile, label);
   if (snippet)
      {
      trfprintf(pOutFile, " (%s)", getName(snippet));
      }
   printInstructionComment(pOutFile, 1, instr);
   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64CompareBranchInstruction *instr)
   {
   printPrefix(pOutFile, instr);

   TR::LabelSymbol *label = instr->getLabelSymbol();
   TR::Snippet *snippet = label ? label->getSnippet() : NULL;
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
   print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, label);
   if (snippet)
      {
      trfprintf(pOutFile, " (%s)", getName(snippet));
      }
   printInstructionComment(pOutFile, 1, instr);
   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64TestBitBranchInstruction *instr)
   {
   printPrefix(pOutFile, instr);

   TR::LabelSymbol *label = instr->getLabelSymbol();
   TR::Snippet *snippet = label ? label->getSnippet() : NULL;
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
   print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   trfprintf(pOutFile, "#%d, ", instr->getBitPos());
   print(pOutFile, label);
   if (snippet)
      {
      trfprintf(pOutFile, " (%s)", getName(snippet));
      }
   printInstructionComment(pOutFile, 1, instr);
   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64RegBranchInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
   print(pOutFile, instr->getTargetRegister(), TR_DoubleWordReg);
   printInstructionComment(pOutFile, 1, instr);
   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64AdminInstruction *instr)
   {
   if (instr->getOpCodeValue() == TR::InstOpCode::assocreg)
      {
      printAssocRegDirective(pOutFile, instr);
      return;
      }

   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s ", getOpCodeName(&instr->getOpCode()));

   TR::Node *node = instr->getNode();
   if (node)
      {
      if (node->getOpCodeValue() == TR::BBStart)
         {
         trfprintf(pOutFile, " (BBStart (block_%d))", node->getBlock()->getNumber());
         }
      else if (node->getOpCodeValue() == TR::BBEnd)
         {
         trfprintf(pOutFile, " (BBEnd (block_%d))", node->getBlock()->getNumber());
         }
      }

   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());

   trfflush(pOutFile);
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1Instruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
   print(pOutFile, instr->getTargetRegister(), TR_WordReg);
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1CondInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   if (instr->getOpCodeValue() == TR::InstOpCode::csincx)
      {
      // cset alias
      trfprintf(pOutFile, "cset \t");
      print(pOutFile, instr->getTargetRegister(), TR_WordReg);
      trfprintf(pOutFile, ", %s", ARM64ConditionNames[cc_invert(instr->getConditionCode())]);
      }
   else
      {
      trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
      print(pOutFile, instr->getTargetRegister(), TR_WordReg);
      trfprintf(pOutFile, ", xzr, xzr, %s", ARM64ConditionNames[instr->getConditionCode()]);
      }
   trfflush(_comp->getOutFile());
   }

/*
 * Convert 8-bit modified immediate constant used in fmovimm instructions
 * to double value
 */
static double
getDoubleFromImm8(uint32_t imm8)
   {
   uint32_t isNegative = imm8 & 0x80;
   uint32_t lower4 = imm8 & 0xf;
   uint32_t upper3 = (imm8 >> 4) & 0x7;
   uint32_t shift = (upper3 <= 3) ? (upper3 + 4) : (upper3 - 4);

   double x = (lower4 + 16) / 16.0;
   double y = (1 << shift) / 8.0;
   double r = x * y;

   return isNegative ? -r : r;
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1ImmInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
   print(pOutFile, instr->getTargetRegister(), TR_WordReg);

   TR::InstOpCode::Mnemonic op = instr->getOpCodeValue();
   if ((op == TR::InstOpCode::adr) || (op == TR::InstOpCode::adrp))
      {
      int64_t offset = static_cast<int64_t>(static_cast<int32_t>(instr->getSourceImmediate()));
      if (instr->getOpCodeValue() == TR::InstOpCode::adrp)
         {
         offset *= 4096;
         }
      trfprintf(pOutFile, ", " POINTER_PRINTF_FORMAT, (instr->getBinaryEncoding() + offset));
      }
   else if ((op == TR::InstOpCode::fmovimms) || (op == TR::InstOpCode::fmovimmd))
      {
      uint32_t imm = instr->getSourceImmediate() & 0xFF;
      trfprintf(pOutFile, ", 0x%02x (%lf)", imm, getDoubleFromImm8(imm));
      }
   else
      {
      uint32_t imm = instr->getSourceImmediate() & 0xFFFF;
      uint32_t shift = (instr->getSourceImmediate() & 0x30000) >> 12;
      trfprintf(pOutFile, ", 0x%04x", imm);
      if (shift != 0)
         {
         trfprintf(pOutFile, ", LSL #%d", shift);
         }
      }
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1ImmSymInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
   print(pOutFile, instr->getTargetRegister(), TR_WordReg);
   trfprintf(pOutFile, ", ");

   auto sym = instr->getSymbol();
   if ((sym != NULL) && sym->isLabel())
      {
      auto label = sym->getLabelSymbol();
      print(pOutFile, label);
      TR::Snippet *snippet = label->getSnippet();
      if (snippet)
         {
         trfprintf(pOutFile, "(%s)", getName(snippet));
         }
      }
   else
      {
      int64_t offset = static_cast<int64_t>(static_cast<int32_t>(instr->getSourceImmediate()));
      if ((instr->getOpCodeValue() != TR::InstOpCode::adr) &&
            (instr->getOpCodeValue() != TR::InstOpCode::adrp))
         {
         // ldr literal variants
         offset *= 4;
         }
      if (instr->getOpCodeValue() == TR::InstOpCode::adrp)
         {
         offset *= 4096;
         }
      trfprintf(pOutFile, POINTER_PRINTF_FORMAT, (instr->getBinaryEncoding() + offset));
      }

   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1Src1Instruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));

   print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource1Register(), TR_WordReg);
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1ZeroSrc1Instruction *instr)
   {
   printPrefix(pOutFile, instr);
   TR::InstOpCode::Mnemonic op = instr->getOpCodeValue();

   if (op == TR::InstOpCode::orrx || op == TR::InstOpCode::orrw)
      {
      // mov alias
      trfprintf(pOutFile, "mov%c \t", (op == TR::InstOpCode::orrx) ? 'x' : 'w');
      }
   else if (op == TR::InstOpCode::ornx || op == TR::InstOpCode::ornw)
      {
      // mvn alias
      trfprintf(pOutFile, "mvn%c \t", (op == TR::InstOpCode::ornx) ? 'x' : 'w');
      }
   else if (op == TR::InstOpCode::subx || op == TR::InstOpCode::subw)
      {
      // neg alias
      trfprintf(pOutFile, "neg%c \t", (op == TR::InstOpCode::subx) ? 'x' : 'w');
      }
   else
      {
      trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
      }

   print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource1Register(), TR_WordReg);
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1Src1ImmInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   TR::InstOpCode::Mnemonic op = instr->getOpCodeValue();
   bool done = false;
   if (op == TR::InstOpCode::subsimmx || op == TR::InstOpCode::subsimmw ||
       op == TR::InstOpCode::addsimmx || op == TR::InstOpCode::addsimmw)
      {
      done = true;
      TR::Register *r = instr->getTargetRegister();
      if (r && r->getRealRegister()
          && toRealRegister(r)->getRegisterNumber() == TR::RealRegister::xzr)
         {
         // cmp/cmn alias
         char *mnemonic = NULL;
         switch (op)
            {
            case TR::InstOpCode::subsimmx:
               mnemonic = "cmpimmx";
               break;
            case TR::InstOpCode::subsimmw:
               mnemonic = "cmpimmw";
               break;
            case TR::InstOpCode::addsimmx:
               mnemonic = "cmnimmx";
               break;
            case TR::InstOpCode::addsimmw:
               mnemonic = "cmnimmw";
            }
         trfprintf(pOutFile, "%s \t", mnemonic);
         print(pOutFile, instr->getSource1Register(), TR_WordReg);
         trfprintf(pOutFile, ", %d", instr->getSourceImmediate());
         }
      else
         {
         trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
         print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
         print(pOutFile, instr->getSource1Register(), TR_WordReg);
         trfprintf(pOutFile, ", %d", instr->getSourceImmediate());
         }
      if (instr->getNbit())
         {
         trfprintf(pOutFile, ", LSL #%d", 12);
         }
      }
   else if ((op == TR::InstOpCode::subimmx || op == TR::InstOpCode::subimmw ||
             op == TR::InstOpCode::addimmx || op == TR::InstOpCode::addimmw))
      {
      done = true;
      trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
      print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
      print(pOutFile, instr->getSource1Register(), TR_WordReg);
      trfprintf(pOutFile, ", %d", instr->getSourceImmediate());
      if (instr->getNbit())
         {
         trfprintf(pOutFile, ", LSL #%d", 12);
         }
      }
   else if (op == TR::InstOpCode::sbfmx || op == TR::InstOpCode::sbfmw)
      {
      uint32_t imm12 = instr->getSourceImmediate();
      auto immr = imm12 >> 6;
      auto imms = imm12 & 0x3f;
      if (op == TR::InstOpCode::sbfmx)
         {
         if (imms == 63)
            {
            // asr alias
            done = true;
            trfprintf(pOutFile, "asrx \t");
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", %d", immr);
            }
         else if ((immr == 0) && ((imms == 7) || (imms == 15) || (imms == 31)))
            {
            // sxtb, sxth or sxtw (signed extend byte|half word|word) alias
            done = true;
            trfprintf(pOutFile, "sxt%cx \t", (imms == 7) ? 'b' : ((imms == 15) ? 'h' : 'w'));
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            }
         }
      else if ((op == TR::InstOpCode::sbfmw) && ((immr & (1 << 6)) == 0) && ((imms & (1 << 6)) == 0))
         {
         if (imms == 31)
            {
            // asr alias
            done = true;
            trfprintf(pOutFile, "asrw \t");
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", %d", immr);
            }
         else if ((immr == 0) && ((imms == 7) || (imms == 15)))
            {
            // sxtb or sxth (signed extend byte|half word) alias
            done = true;
            trfprintf(pOutFile, "sxt%cw \t", (imms == 7) ? 'b' : 'h');
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg); 
            }
         }
      if (!done)
         {
         done = true;
         trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
         print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
         print(pOutFile, instr->getSource1Register(), TR_WordReg);
         trfprintf(pOutFile, ", %d, %d", immr, imms);
         }
      }
   else if (op == TR::InstOpCode::ubfmx || op == TR::InstOpCode::ubfmw)
      {
      uint32_t imm12 = instr->getSourceImmediate();
      auto immr = imm12 >> 6;
      auto imms = imm12 & 0x3f;
      if (op == TR::InstOpCode::ubfmx)
         {
         if (imms == 63)
            {
            // lsr alias
            done = true;
            trfprintf(pOutFile, "lsrx \t");
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", %d", immr);
            }
         else if (imms + 1 == immr)
            {
            // lsl alias
            done = true;
            trfprintf(pOutFile, "lslx \t");
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", %d", 63 - imms);
            }
         else if (imms < immr)
            {
            // ubfiz alias
            done = true;
            trfprintf(pOutFile, "ubfizx \t");
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", %d, %d", 64 - immr, imms + 1);
            }
         else
            {
            // ubfx alias
            done = true;
            trfprintf(pOutFile, "ubfxx \t");
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", %d, %d", immr, imms + 1 - immr);
            }
         }
      else if ((op == TR::InstOpCode::ubfmw) && ((immr & (1 << 6)) == 0) && ((imms & (1 << 6)) == 0))
         {
         if (imms == 31)
            {
            // lsr alias
            done = true;
            trfprintf(pOutFile, "lsrw \t");
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", %d", immr);
            }
         else if (imms + 1 == immr)
            {
            // lsl alias
            done = true;
            trfprintf(pOutFile, "lslw \t");
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", %d", 31 - imms);
            }
         else if ((immr == 0) && ((imms == 7) || (imms == 15)))
            {
            // uxtb or uxth (unsigned extend byte|half word) alias
            done = true;
            trfprintf(pOutFile, "uxt%cx \t", (imms == 7) ? 'b' : 'h');
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            }
         else if (imms < immr)
            {
            // ubfiz alias
            done = true;
            trfprintf(pOutFile, "ubfizw \t");
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", %d, %d", 32 - immr, imms + 1);
            }
         else
            {
            // ubfx alias
            done = true;
            trfprintf(pOutFile, "ubfxw \t");
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", %d, %d", immr, imms + 1 - immr);
            }
         }
      if (!done)
         {
         done = true;
         trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
         print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
         print(pOutFile, instr->getSource1Register(), TR_WordReg);
         trfprintf(pOutFile, ", %d, %d", immr, imms);
         }
      }
   else if (op == TR::InstOpCode::andimmx || op == TR::InstOpCode::andimmw ||
            op == TR::InstOpCode::andsimmx || op == TR::InstOpCode::andsimmw ||
            op == TR::InstOpCode::orrimmx || op == TR::InstOpCode::orrimmw ||
            op == TR::InstOpCode::eorimmx || op == TR::InstOpCode::eorimmw)
      {
      uint32_t imm12 = instr->getSourceImmediate();
      auto immr = imm12 >> 6;
      auto imms = imm12 & 0x3f;
      auto n = instr->getNbit();
      if (op == TR::InstOpCode::andimmx || op == TR::InstOpCode::andsimmx ||
          op == TR::InstOpCode::orrimmx || op == TR::InstOpCode::eorimmx)
         {
         uint64_t immediate;
         if (decodeBitMasks(n, immr, imms, immediate))
            {
            done = true;
            trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", 0x%llx", immediate);
            }
         }
      else
         {
         uint32_t immediate;
         if (decodeBitMasks(n, immr, imms, immediate))
            {
            done = true;
            trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
            print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", 0x%lx", immediate);
            }
         }
      }

   if (!done)
      {
      trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
      print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
      print(pOutFile, instr->getSource1Register(), TR_WordReg);
      trfprintf(pOutFile, ", %d", instr->getSourceImmediate());
      }

   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());

   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1ZeroImmInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   TR::InstOpCode::Mnemonic op = instr->getOpCodeValue();
   bool done = false;
   if (op == TR::InstOpCode::orrimmx || op == TR::InstOpCode::orrimmw)
      {
      // mov (bitmask immediate) alias
      uint32_t imm12 = instr->getSourceImmediate();
      auto immr = imm12 >> 6;
      auto imms = imm12 & 0x3f;
      auto n = instr->getNbit();
      if (op == TR::InstOpCode::orrimmx)
         {
         uint64_t immediate;
         if (decodeBitMasks(n, immr, imms, immediate))
            {
            done = true;
            trfprintf(pOutFile, "movx \t");
            print(pOutFile, instr->getTargetRegister(), TR_WordReg);
            trfprintf(pOutFile, ", 0x%llx", immediate);
            }
         }
      else
         {
         uint32_t immediate;
         if (decodeBitMasks(n, immr, imms, immediate))
            {
            done = true;
            trfprintf(pOutFile, "movw \t");
            print(pOutFile, instr->getTargetRegister(), TR_WordReg);
            trfprintf(pOutFile, ", 0x%lx", immediate);
            }
         }
      }
   if (!done)
      {
      trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
      print(pOutFile, instr->getTargetRegister(), TR_WordReg);
      trfprintf(pOutFile, ", %d", instr->getSourceImmediate());
      }

   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());

   trfflush(_comp->getOutFile());
   }
void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64ZeroSrc1ImmInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   TR::InstOpCode::Mnemonic op = instr->getOpCodeValue();
   bool done = false;
   if (op == TR::InstOpCode::subsimmx || op == TR::InstOpCode::subsimmw)
      {
      // cmp alias
      done = true;
      trfprintf(pOutFile, "cmpimm%c \t", (op == TR::InstOpCode::subsimmx) ? 'x' : 'w');
      print(pOutFile, instr->getSource1Register(), TR_WordReg);
      trfprintf(pOutFile, ", %d", instr->getSourceImmediate());
      if (instr->getNbit())
         {
         trfprintf(pOutFile, ", LSL #%d", 12);
         }
      }
   else if (op == TR::InstOpCode::addsimmx || op == TR::InstOpCode::addsimmw)
      {
      // cmn alias
      done = true;
      trfprintf(pOutFile, "cmnimm%c \t", (op == TR::InstOpCode::addsimmx) ? 'x' : 'w');
      print(pOutFile, instr->getSource1Register(), TR_WordReg);
      trfprintf(pOutFile, ", %d", instr->getSourceImmediate());
      if (instr->getNbit())
         {
         trfprintf(pOutFile, ", LSL #%d", 12);
         }
      }
   else if (op == TR::InstOpCode::andsimmx || op == TR::InstOpCode::andsimmw)
      {
      // tst alias
      uint32_t imm12 = instr->getSourceImmediate();
      auto immr = imm12 >> 6;
      auto imms = imm12 & 0x3f;
      auto n = instr->getNbit();
      if (op == TR::InstOpCode::andsimmx)
         {
         uint64_t immediate;
         if (decodeBitMasks(n, immr, imms, immediate))
            {
            done = true;
            trfprintf(pOutFile, "tstimmx \t");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", 0x%llx", immediate);
            }
         }
      else
         {
         uint32_t immediate;
         if (decodeBitMasks(n, immr, imms, immediate))
            {
            done = true;
            trfprintf(pOutFile, "tstimmw \t");
            print(pOutFile, instr->getSource1Register(), TR_WordReg);
            trfprintf(pOutFile, ", 0x%lx", immediate);
            }
         }
      }

   if (!done)
      {
      trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
      print(pOutFile, instr->getSource1Register(), TR_WordReg);
      trfprintf(pOutFile, ", %d", instr->getSourceImmediate());
      }

   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1Src2Instruction *instr)
   {
   printPrefix(pOutFile, instr);
   TR::InstOpCode::Mnemonic op = instr->getOpCodeValue();
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
   print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource2Register(), TR_WordReg);

   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());

   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64ZeroSrc2Instruction *instr)
   {
   printPrefix(pOutFile, instr);
   TR::InstOpCode::Mnemonic op = instr->getOpCodeValue();
   if (op == TR::InstOpCode::subsx || op == TR::InstOpCode::subsw)
      {
      // cmp alias
      trfprintf(pOutFile, "cmp%c \t", (op == TR::InstOpCode::subsx) ? 'x' : 'w');
      }
   else if (op == TR::InstOpCode::addsx || op == TR::InstOpCode::addsw)
      {
      // cmn alias
      trfprintf(pOutFile, "cmn%c \t", (op == TR::InstOpCode::addsx) ? 'x' : 'w');
      }
   else if (op == TR::InstOpCode::andsx || op == TR::InstOpCode::andsw)
      {
      // tst alias
      trfprintf(pOutFile, "tst%c \t", (op == TR::InstOpCode::andsx) ? 'x' : 'w');
      }
   else
      {
      trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
      }
   print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource2Register(), TR_WordReg);

   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64CondTrg1Src2Instruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));

   print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource2Register(), TR_WordReg);
   trfprintf(pOutFile, ", %s", ARM64ConditionNames[instr->getConditionCode()]);

   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());

   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1Src2ShiftedInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   TR::InstOpCode::Mnemonic op = instr->getOpCodeValue();
   if ((op == TR::InstOpCode::extrw || op == TR::InstOpCode::extrx) &&
         (instr->getSource1Register() == instr->getSource2Register()))
      {
      // ror alias
      trfprintf(pOutFile, "ror%c \t", (op == TR::InstOpCode::extrx) ? 'x' : 'w');
      print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
      print(pOutFile, instr->getSource1Register(), TR_WordReg);
      trfprintf(pOutFile, ", #%d", instr->getShiftAmount());
      }
   else
      {
      trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));

      print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
      print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
      print(pOutFile, instr->getSource2Register(), TR_WordReg);
      trfprintf(pOutFile, " %s %d", ARM64ShiftCodeNames[instr->getShiftType()], instr->getShiftAmount());
      }

   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1Src2ExtendedInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));

   print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource2Register(), TR_WordReg);
   trfprintf(pOutFile, " %s %d", ARM64ExtendCodeNames[instr->getExtendType()], instr->getShiftAmount());
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1Src2ZeroInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   TR::InstOpCode::Mnemonic op = instr->getOpCodeValue();
   if (op == TR::InstOpCode::maddx || op == TR::InstOpCode::maddw)
      {
      // mul alias
      trfprintf(pOutFile, "mul%c \t", (op == TR::InstOpCode::maddx) ? 'x' : 'w');
      }
   else
      {
      trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
      }
   print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource2Register(), TR_WordReg);
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1Src3Instruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
   print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource2Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource3Register(), TR_WordReg);

   if (instr->getDependencyConditions())
      print(pOutFile, instr->getDependencyConditions());

   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1MemInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));

   print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");

   print(pOutFile, instr->getMemoryReference());
   TR::Symbol *symbol = instr->getMemoryReference()->getSymbolReference()->getSymbol();
   if (symbol && symbol->isSpillTempAuto())
      {
      trfprintf(pOutFile, "\t\t; spilled for %s", getName(instr->getNode()->getOpCode()));
      }
   if (instr->getSnippetForGC() != NULL)
      {
      trfprintf(pOutFile, "\t\t; Backpatched branch to Unresolved Data %s", getName(instr->getSnippetForGC()->getSnippetLabel()));
      }

   printMemoryReferenceComment(pOutFile, instr->getMemoryReference());
   printInstructionComment(pOutFile, 1, instr);
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64MemInstruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
   print(pOutFile, instr->getMemoryReference());
   printMemoryReferenceComment(pOutFile, instr->getMemoryReference());
   printInstructionComment(pOutFile, 1, instr);
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64MemImmInstruction *instr)
   {
   TR::InstOpCode::Mnemonic op = instr->getOpCodeValue();
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
   if ((op == TR::InstOpCode::prfmoff || op == TR::InstOpCode::prfmimm))
      {
      uint32_t immediate = instr->getImmediate();
      uint32_t typeValue = (immediate >> 3) & 0x3;
      uint32_t targetValue = (immediate >> 1) & 0x3;
      if ((typeValue != 3) && (targetValue != 3))
         {
         ARM64PrefetchType type = static_cast<ARM64PrefetchType>(typeValue);
         ARM64PrefetchTarget target = static_cast<ARM64PrefetchTarget>(targetValue);
         ARM64PrefetchPolicy policy = static_cast<ARM64PrefetchPolicy>(immediate  & 0x1);
         trfprintf(pOutFile, "%s%s%s, ", (type == ARM64PrefetchType::LOAD) ? "pld" : ((type == ARM64PrefetchType::INSTRUCTION) ? "pli" : "pst"),
                                         (target == ARM64PrefetchTarget::L1) ? "l1" :  ((target == ARM64PrefetchTarget::L2) ? "l2" : "l3"),
                                         (policy == ARM64PrefetchPolicy::KEEP) ? "keep" : "strm");
         }
      else
         {
         trfprintf(pOutFile, "#%d, ", instr->getImmediate());
         }
      }
   else
      {
      trfprintf(pOutFile, "#%d, ", instr->getImmediate());
      }
   print(pOutFile, instr->getMemoryReference());
   printMemoryReferenceComment(pOutFile, instr->getMemoryReference());
   printInstructionComment(pOutFile, 1, instr);
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64MemSrc1Instruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));

   print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getMemoryReference());

   printMemoryReferenceComment(pOutFile, instr->getMemoryReference());
   printInstructionComment(pOutFile, 1, instr);
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64MemSrc2Instruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));

   print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource2Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getMemoryReference());

   printMemoryReferenceComment(pOutFile, instr->getMemoryReference());
   printInstructionComment(pOutFile, 1, instr);
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Trg1MemSrc1Instruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));

   print(pOutFile, instr->getTargetRegister(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getMemoryReference());

   printMemoryReferenceComment(pOutFile, instr->getMemoryReference());
   printInstructionComment(pOutFile, 1, instr);
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Src1Instruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
   print(pOutFile, instr->getSource1Register(), TR_WordReg);
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::ARM64Src2Instruction *instr)
   {
   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s \t", getOpCodeName(&instr->getOpCode()));
   print(pOutFile, instr->getSource1Register(), TR_WordReg); trfprintf(pOutFile, ", ");
   print(pOutFile, instr->getSource2Register(), TR_WordReg);

   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::RegisterDependency *dep)
   {
   trfprintf(pOutFile,"[");
   print(pOutFile, dep->getRegister(), TR_WordReg);
   trfprintf(pOutFile," : ");
   trfprintf(pOutFile,"%s] ", getARM64RegisterName(dep->getRealRegister()));
   trfflush(_comp->getOutFile());
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::RegisterDependencyConditions *conditions)
   {
    if (conditions)
      {
      int i;
      trfprintf(pOutFile,"\n PRE: ");
      for (i=0; i<conditions->getAddCursorForPre(); i++)
         {
         print(pOutFile, conditions->getPreConditions()->getRegisterDependency(i));
         }
      trfprintf(pOutFile,"\nPOST: ");
      for (i=0; i<conditions->getAddCursorForPost(); i++)
         {
         print(pOutFile, conditions->getPostConditions()->getRegisterDependency(i));
         }
      trfflush(_comp->getOutFile());
      }
   }

void
TR_Debug::printAssocRegDirective(TR::FILE *pOutFile, TR::Instruction *instr)
   {
   TR::RegisterDependencyGroup * depGroup = instr->getDependencyConditions()->getPostConditions();

   printPrefix(pOutFile, instr);
   trfprintf(pOutFile, "%s", getOpCodeName(&instr->getOpCode()));
   trfflush(pOutFile);

   auto numPostConditions = instr->getDependencyConditions()->getAddCursorForPost();
   for (int i = 0; i < numPostConditions; i++)
      {
      TR::RegisterDependency *dependency = depGroup->getRegisterDependency(i);
      TR::Register *virtReg = dependency->getRegister();

      if (virtReg)
         {
         print(pOutFile, dependency);
         }
      }

   trfflush(pOutFile);
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::MemoryReference *mr)
   {
   trfprintf(pOutFile, "[");

   if (mr->getBaseRegister() != NULL)
      {
      print(pOutFile, mr->getBaseRegister());
      trfprintf(pOutFile, ", ");
      }

   if (mr->getIndexRegister() != NULL)
      {
      print(pOutFile, mr->getIndexRegister());
      TR::ARM64ExtendCode extendCode = mr->getIndexExtendCode();
      uint8_t scale = mr->getScale();

      if ((extendCode != TR::ARM64ExtendCode::EXT_UXTX) || (scale != 0))
         {
         if (extendCode != TR::ARM64ExtendCode::EXT_UXTX)
            {
            trfprintf(pOutFile, ", %s %d", ARM64ExtendCodeNames[extendCode], scale);
            }
         else
            {
            trfprintf(pOutFile, ", lsl %d", scale);
            }
         }
      }
   else
      trfprintf(pOutFile, "%d", mr->getOffset(true));

   trfprintf(pOutFile, "]");
   }

void
TR_Debug::printARM64GCRegisterMap(TR::FILE *pOutFile, TR::GCRegisterMap *map)
   {
   TR::Machine *machine = _cg->machine();

   trfprintf(pOutFile, "    registers: {");
   for (int i = 0; i < 32; i++)
      {
      if (map->getMap() & (1 << i))
         trfprintf(pOutFile, "%s ", getName(machine->getRealRegister((TR::RealRegister::RegNum)(i + TR::RealRegister::FirstGPR))));
      }

   trfprintf(pOutFile, "}\n");
   }

void
TR_Debug::print(TR::FILE *pOutFile, TR::RealRegister *reg, TR_RegisterSizes size)
   {
   trfprintf(pOutFile, "%s", getName(reg, size));
   }

static const char *
getRegisterName(TR::RealRegister::RegNum num, bool is64bit)
   {
   switch (num)
      {
      case TR::RealRegister::NoReg: return "NoReg";
      case TR::RealRegister::SpilledReg: return "SpilledReg";
      case TR::RealRegister::x0: return (is64bit ? "x0" : "w0");
      case TR::RealRegister::x1: return (is64bit ? "x1" : "w1");
      case TR::RealRegister::x2: return (is64bit ? "x2" : "w2");
      case TR::RealRegister::x3: return (is64bit ? "x3" : "w3");
      case TR::RealRegister::x4: return (is64bit ? "x4" : "w4");
      case TR::RealRegister::x5: return (is64bit ? "x5" : "w5");
      case TR::RealRegister::x6: return (is64bit ? "x6" : "w6");
      case TR::RealRegister::x7: return (is64bit ? "x7" : "w7");
      case TR::RealRegister::x8: return (is64bit ? "x8" : "w8");
      case TR::RealRegister::x9: return (is64bit ? "x9" : "w9");
      case TR::RealRegister::x10: return (is64bit ? "x10" : "w10");
      case TR::RealRegister::x11: return (is64bit ? "x11" : "w11");
      case TR::RealRegister::x12: return (is64bit ? "x12" : "w12");
      case TR::RealRegister::x13: return (is64bit ? "x13" : "w13");
      case TR::RealRegister::x14: return (is64bit ? "x14" : "w14");
      case TR::RealRegister::x15: return (is64bit ? "x15" : "w15");
      case TR::RealRegister::x16: return (is64bit ? "x16" : "w16");
      case TR::RealRegister::x17: return (is64bit ? "x17" : "w17");
      case TR::RealRegister::x18: return (is64bit ? "x18" : "w18");
      case TR::RealRegister::x19: return (is64bit ? "x19" : "w19");
      case TR::RealRegister::x20: return (is64bit ? "x20" : "w20");
      case TR::RealRegister::x21: return (is64bit ? "x21" : "w21");
      case TR::RealRegister::x22: return (is64bit ? "x22" : "w22");
      case TR::RealRegister::x23: return (is64bit ? "x23" : "w23");
      case TR::RealRegister::x24: return (is64bit ? "x24" : "w24");
      case TR::RealRegister::x25: return (is64bit ? "x25" : "w25");
      case TR::RealRegister::x26: return (is64bit ? "x26" : "w26");
      case TR::RealRegister::x27: return (is64bit ? "x27" : "w27");
      case TR::RealRegister::x28: return (is64bit ? "x28" : "w28");
      case TR::RealRegister::x29: return (is64bit ? "x29" : "w29");
      case TR::RealRegister::x30: return "lr";
      case TR::RealRegister::sp: return "sp";
      case TR::RealRegister::xzr: return (is64bit ? "xzr" : "wzr");

      case TR::RealRegister::v0: return (is64bit ? "d0" : "s0");
      case TR::RealRegister::v1: return (is64bit ? "d1" : "s1");
      case TR::RealRegister::v2: return (is64bit ? "d2" : "s2");
      case TR::RealRegister::v3: return (is64bit ? "d3" : "s3");
      case TR::RealRegister::v4: return (is64bit ? "d4" : "s4");
      case TR::RealRegister::v5: return (is64bit ? "d5" : "s5");
      case TR::RealRegister::v6: return (is64bit ? "d6" : "s6");
      case TR::RealRegister::v7: return (is64bit ? "d7" : "s7");
      case TR::RealRegister::v8: return (is64bit ? "d8" : "s8");
      case TR::RealRegister::v9: return (is64bit ? "d9" : "s9");
      case TR::RealRegister::v10: return (is64bit ? "d10" : "s10");
      case TR::RealRegister::v11: return (is64bit ? "d11" : "s11");
      case TR::RealRegister::v12: return (is64bit ? "d12" : "s12");
      case TR::RealRegister::v13: return (is64bit ? "d13" : "s13");
      case TR::RealRegister::v14: return (is64bit ? "d14" : "s14");
      case TR::RealRegister::v15: return (is64bit ? "d15" : "s15");
      case TR::RealRegister::v16: return (is64bit ? "d16" : "s16");
      case TR::RealRegister::v17: return (is64bit ? "d17" : "s17");
      case TR::RealRegister::v18: return (is64bit ? "d18" : "s18");
      case TR::RealRegister::v19: return (is64bit ? "d19" : "s19");
      case TR::RealRegister::v20: return (is64bit ? "d20" : "s20");
      case TR::RealRegister::v21: return (is64bit ? "d21" : "s21");
      case TR::RealRegister::v22: return (is64bit ? "d22" : "s22");
      case TR::RealRegister::v23: return (is64bit ? "d23" : "s23");
      case TR::RealRegister::v24: return (is64bit ? "d24" : "s24");
      case TR::RealRegister::v25: return (is64bit ? "d25" : "s25");
      case TR::RealRegister::v26: return (is64bit ? "d26" : "s26");
      case TR::RealRegister::v27: return (is64bit ? "d27" : "s27");
      case TR::RealRegister::v28: return (is64bit ? "d28" : "s28");
      case TR::RealRegister::v29: return (is64bit ? "d29" : "s29");
      case TR::RealRegister::v30: return (is64bit ? "d30" : "s30");
      case TR::RealRegister::v31: return (is64bit ? "d31" : "s31");

      default: return "???";
      }
   }

const char *
TR_Debug::getName(TR::RealRegister *reg, TR_RegisterSizes size)
   {
   return getRegisterName(reg->getRegisterNumber(), (size == TR_DoubleWordReg || size == TR_DoubleReg));
   }

const char *
TR_Debug::getARM64RegisterName(uint32_t regNum, bool is64bit)
   {
   return getRegisterName((TR::RealRegister::RegNum)regNum, is64bit);
   }

void TR_Debug::printARM64OOLSequences(TR::FILE *pOutFile)
   {
   auto oiIterator = _cg->getARM64OutOfLineCodeSectionList().begin();

   while (oiIterator != _cg->getARM64OutOfLineCodeSectionList().end())
      {
      trfprintf(pOutFile, "\n------------ start out-of-line instructions\n");
      TR::Instruction *instr = (*oiIterator)->getFirstInstruction();

      do {
         print(pOutFile, instr);
         instr = instr->getNext();
      } while (instr != (*oiIterator)->getAppendInstruction());

      if ((*oiIterator)->getAppendInstruction())
         {
         print(pOutFile, (*oiIterator)->getAppendInstruction());
         }
      trfprintf(pOutFile, "\n------------ end out-of-line instructions\n");

      ++oiIterator;
      }
   }

const char *
TR_Debug::getNamea64(TR::Snippet * snippet)
   {
   switch (snippet->getKind())
      {
      case TR::Snippet::IsCall:
         return "Call Snippet";
         break;
      case TR::Snippet::IsUnresolvedCall:
         return "Unresolved Call Snippet";
         break;
      case TR::Snippet::IsVirtualUnresolved:
         return "Unresolved Virtual Call Snippet";
         break;
      case TR::Snippet::IsInterfaceCall:
         return "Interface Call Snippet";
         break;
      case TR::Snippet::IsStackCheckFailure:
         return "Stack Check Failure Snippet";
         break;
      case TR::Snippet::IsUnresolvedData:
         return "Unresolved Data Snippet";
         break;
      case TR::Snippet::IsConstantData:
         return "Constant Data Snippet";
         break;
      case TR::Snippet::IsRecompilation:
         return "Recompilation Snippet";
         break;
      case TR::Snippet::IsHelperCall:
         return "Helper Call Snippet";
         break;
      case TR::Snippet::IsMonitorEnter:
         return "MonitorEnter Inc Counter";
         break;
      case TR::Snippet::IsMonitorExit:
         return "MonitorExit Dec Counter";
         break;
      case TR::Snippet::IsHeapAlloc:
         return "Heap Alloc Snippet";
         break;
      default:
         return "<unknown snippet>";
      }
   }

void
TR_Debug::printa64(TR::FILE *pOutFile, TR::Snippet * snippet)
   {
   if (pOutFile == NULL)
      return;
   switch (snippet->getKind())
      {
#ifdef J9_PROJECT_SPECIFIC
      case TR::Snippet::IsCall:
         print(pOutFile, (TR::ARM64CallSnippet *)snippet);
         break;
      case TR::Snippet::IsUnresolvedCall:
         print(pOutFile, (TR::ARM64UnresolvedCallSnippet *)snippet);
         break;
      case TR::Snippet::IsVirtualUnresolved:
         print(pOutFile, (TR::ARM64VirtualUnresolvedSnippet *)snippet);
         break;
      case TR::Snippet::IsInterfaceCall:
         print(pOutFile, (TR::ARM64InterfaceCallSnippet *)snippet);
         break;
      case TR::Snippet::IsStackCheckFailure:
         print(pOutFile, (TR::ARM64StackCheckFailureSnippet *)snippet);
         break;
      case TR::Snippet::IsForceRecompilation:
         print(pOutFile, (TR::ARM64ForceRecompilationSnippet *)snippet);
         break;
      case TR::Snippet::IsRecompilation:
         print(pOutFile, (TR::ARM64RecompilationSnippet *)snippet);
         break;
#endif
      case TR::Snippet::IsHelperCall:
         print(pOutFile, (TR::ARM64HelperCallSnippet *)snippet);
         break;
      case TR::Snippet::IsUnresolvedData:
         print(pOutFile, (TR::UnresolvedDataSnippet *)snippet);
         break;
      case TR::Snippet::IsConstantData:
         print(pOutFile, (TR::ARM64ConstantDataSnippet*)snippet);
         break;

      case TR::Snippet::IsMonitorExit:
      case TR::Snippet::IsMonitorEnter:
      case TR::Snippet::IsHeapAlloc:
         snippet->print(pOutFile, this);
         break;
      default:
         TR_ASSERT( 0, "unexpected snippet kind");
      }
   }

// This function assumes that if a trampoline is required then it must be to a helper function.
// Use this API only for inquiring about branches to helpers.
bool
TR_Debug::isBranchToTrampoline(TR::SymbolReference *symRef, uint8_t *cursor, int32_t &distance)
   {
   uintptr_t target = (uintptr_t)symRef->getMethodAddress();
   bool requiresTrampoline = false;

   if (_cg->directCallRequiresTrampoline(target, (intptr_t)cursor))
      {
      target = TR::CodeCacheManager::instance()->findHelperTrampoline(symRef->getReferenceNumber(), (void *)cursor);
      requiresTrampoline = true;
      }

   distance = (int32_t)(target - (intptr_t)cursor);
   return requiresTrampoline;
   }
