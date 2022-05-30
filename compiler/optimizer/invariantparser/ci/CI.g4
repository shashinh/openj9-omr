grammar CI;

ci: ( ciEntry (NEWLINE ciEntry)* )? (NEWLINE|EOF);
ciEntry: ( (ciBciEntry) (' ' (ciBciEntry))*);
ciBciEntry2: NUMS;


ciBciEntry: ciEntries | STRING | CONST | GLOBAL | NIL;

ciEntries: callerIndex '-' ( (bciVal)('.' (bciVal))*);

callerIndex : NUMS;
bciKey : NUMS;
bciVal : NUMS | NIL;
fieldKey: ALPHAS;

NIL : 'N';
STRING: 'S';
CONST: 'C';
GLOBAL: 'G';
NUMS: [0-9]+;
ALPHAS: [A-Za-z]+;
NEWLINE: [\r\n]+;
ALL: [A-Za-z<>-]+;
