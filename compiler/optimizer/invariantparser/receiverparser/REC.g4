grammar REC;

recs : (entry ';')* (NEWLINE | EOF);
entry : bciKey ' ' clazzes;
clazzes : clazz ( ' ' (clazz) )*;
clazz : NUMS;
bciKey : NUMS;

NUMS : [0-9]+;
NEWLINE: [\r\n]+;
