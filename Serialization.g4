grammar Serialization;

s : operationList EOF ;



variable : ID ;
monomial: '(' (variable '^' INT)* ')' ;
term: RATIONAL monomial;
polynomial: '[' (term)* ']' ;

operation: '{' ID (',' (monomial|term|polynomial))+ '}' ; 
operationList : '{' (operation)* '}' ;



INT     : [0-9]+ ;
RATIONAL:  ('-')? INT '/' INT ;
ID : [a-zA-Z] [a-zA-Z0-9]* ;

