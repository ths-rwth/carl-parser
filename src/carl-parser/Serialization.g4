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
start : carl_expr EOF ;

carl_expr
    : formula_nary
    | formula_unary
    | constraint
    | arith_nary
    | arith_unary
    | boolean
    | number
    | real_variable
    ;

form_expr
    : formula_nary
    | formula_unary
    | constraint
    | boolean
    | bool_variable
    ;

formula_nary : LPAREN form_op_nary form_expr+ RPAREN;
form_op_nary : 'and' | 'or' | '=' | 'xor' | '=>' | 'ite';

formula_unary : LPAREN token='not' form_expr RPAREN;

// NEQ not directly written ( is not = )
constraint : LPAREN token=('=' | '<' | '<=' | '>' | '>=' | '!=') left=arith_expr arith_expr RPAREN;

arith_expr
    : arith_nary
    | arith_unary
    | number
    | real_variable
    ;

arith_unary : LPAREN token=('+' | '-') arith_expr RPAREN;
arith_nary : LPAREN token=('+' | '-' | '*' | '/') arith_expr arith_expr+ RPAREN;


boolean : TRUE | FALSE;
number : NUMERAL | DECIMAL | HEXADECIMAL | BINARY;
real_variable : SYMBOL;
bool_variable : SYMBOL;

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

TRUE : 'true';
FALSE: 'false';

fragment DIGIT : [0-9];
fragment LETTER : [A-Za-z];
NUMERAL : '0' | '-'?([1-9]DIGIT*);
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
