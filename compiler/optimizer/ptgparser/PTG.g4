grammar PTG;


ptg: (entry ( ';' entry)* )? (NEWLINE | EOF);
entry: bciKey ':' '(' vars   ')' ('(' fields ')')?;

vars: (varentry (',' varentry)*)?;
varentry : bciKey ':' ( (bciVal) (' ' (bciVal))*);
fields: (fieldentry (',' fieldentry)*)?;
fieldentry : bciKeyField '.' field ':' ( (bciVal) (' ' bciVal)*);

bciKeyField: NUMS;
field : ALPHAS;
bciKey: ALL | NUMS;
bciVal : NUMS | NIL;
NIL : 'n';
NUMS: [0-9]+;
ALPHAS: [A-Za-z]+;
NEWLINE: [\r\n]+;
ALL: [A-Za-z<>-]+;
