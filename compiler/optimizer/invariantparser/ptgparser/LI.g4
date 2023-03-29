grammar LI;


ptg: (entry ( ';' entry)* )? (NEWLINE | EOF);
entry: bciKey ':' '(' vars   ')' ('(' fields ')')?;

vars: (varentry (',' varentry)*)?;
varentry : bciKey ':' ( (ciBciEntry) (' ' (ciBciEntry))*);

fields: (fieldentry (',' fieldentry)*)?;
fieldentry : callerIndex '-' bciKey '('  (field) ((',' (field))*) ')';

field : fieldKey ':'  (ciBciEntry) (' ' (ciBciEntry))*;

ciBciEntry: ciEntries | STRING | CONST | GLOBAL | NIL;

//each bciVal to be associated with a type (numeric)
//ciEntries: callerIndex '-' ( (bciVal)('.' (bciVal))*);
ciEntries: callerIndex '-' ( (bciValWithType)('.' (bciValWithType))*);

callerIndex : NUMS;
bciKey : NUMS;
//bciVal : NUMS | NIL;
type : NUMS;
bciValWithType : bciKey '-' type | NIL;
fieldKey: ALPHAS;

NIL : 'N';
STRING: 'S';
CONST: 'C';
GLOBAL: 'G';
NUMS: [0-9]+;
ALPHAS: [a-zA-Z0-9$_]+;
NEWLINE: [\r\n]+;
ALL: [A-Za-z<>-]+;
