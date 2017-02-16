grammar Polynomial;

s : polynomial EOF ;



variable : ID ;
monomial: '(' (variable '^' INT)* ')' ;
term: RATIONAL monomial;
polynomial: '(' (term)* ')' ;

INT     : [0-9]+ ;
RATIONAL:  ('-')? INT '/' INT ;
ID : [a-zA-Z] [a-zA-Z0-9]* ;
