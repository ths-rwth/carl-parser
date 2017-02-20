grammar Serialization;

s : operation EOF ;



variable : ID ;
monomial: '(' (variable '^' INT)* ')' ;
term: RATIONAL monomial;
polynomial: '[' (term)* ']' ;

operation: '{' ID (',' (monomial|term|polynomial))+ '}' ; 



INT     : [0-9]+ ;
RATIONAL:  ('-')? INT '/' INT ;
ID : [a-zA-Z] [a-zA-Z0-9]* ;

