/**
 * Grammar used to represent formulas and all they can contain in CaRL,
 * based on the SMTLIB 2.5 standard.
 * In particular, it can parse a subset of Terms, and contains many
 * a hardcoded symbol/qualifying identifier
 */

grammar Serialization;

///////////////////////////////
// Rules
///////////////////////////////
start : form_expr EOF ;

form_expr : LPAREN form_expr RPAREN | form_expr_body;
form_expr_body
    : formula_nary
    | formula_unary
    | constraint
    | arith_expr_body
    | atom
    ;

formula_nary : form_op_nary form_expr+;
form_op_nary : 'and' | 'or' | '=' | 'xor' | '=>' | 'ite';

formula_unary : 'not' form_expr;

constraint : relation arith_expr_body '0';
// NEQ not directly written ( is not = )
relation : '=' | '<' | '<=' | '>' | '>=';

arith_expr : LPAREN arith_expr RPAREN | arith_expr_body;
arith_expr_body
    : ('+' | '-' | '*' | '/') arith_expr+
    | atom
    ;

atom : 'true' | 'false' | number | variable;
number : NUMERAL | DECIMAL | HEXADECIMAL | BINARY;
variable : SYMBOL;

//variable_type : 'Bool' | 'Real' | '?_Uninterpreted' | '?_Bitvector';


///////////////////////////////
// Tokens
///////////////////////////////
TBINARY : 'BINARY';
TDECIMAL : 'DECIMAL';
THEXADECIMAL : 'HEXADECIMAL';
TNUMERAL : 'NUMERAL';
TSTRING : 'STRING';

LPAREN : '(';
RPAREN : ')';
INDEXER : '_';
ANNOTATION : '!';

AS : 'as';
LET : 'let';
EXISTS : 'exists';
FORALL : 'forall';
PAR : 'par';

fragment DIGIT : [0-9];
fragment LETTER : [A-Za-z];
NUMERAL : '0' | [1-9]DIGIT*;
DECIMAL : NUMERAL '.' DIGIT+;
HEXADECIMAL : '#x' [0-9A-Fa-f]+;
BINARY: '#b' [0-1]+;

STRING : '"' ( '""' | ~["] )* '"';

fragment SIMPLE_SYM : (LETTER | [~!@$%^&*_\-+=<>.?/]) (LETTER | DIGIT | [~!@$%^&*_\-+=<>.?/])*;
//TODO: Incomplete spec for QUOTED_SYM (printable char)
fragment QUOTED_SYM : '|' (LETTER | DIGIT)+ '|';

// QUOTED_SYM removed for simplification
SYMBOL : SIMPLE_SYM; // | QUOTED_SYM;

KEYWORD : ':' SIMPLE_SYM;

// Whitespace according to SMTLIB spec
WS: [ \n\t\r]+ -> skip;
