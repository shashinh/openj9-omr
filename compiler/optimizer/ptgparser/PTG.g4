grammar PTG;


ptg: (entry ( ';' entry)* )? (NEWLINE | EOF);
entry: bciKey ':' '(' vars   ')' ('(' fields ')')?;

vars: (varentry (',' varentry)*)?;
varentry : bciKey ':' ( (ciBciEntry) (' ' (ciBciEntry))*);

fields: (fieldentry (',' fieldentry)*)?;
fieldentry : callerIndex '-' bciKey '('  (field) ((',' (field))*) ')';

field : fieldKey ':'  (ciBciEntry) (' ' (ciBciEntry))*;

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
