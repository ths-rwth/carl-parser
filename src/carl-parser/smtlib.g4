/**
 * Grammar based on the SMTLIB 2.5 standard.
 */

grammar smtlib;

/**
 * 3.2 S-expr
 */
spec_constant : NUMERAL | DECIMAL | HEXADECIMAL | BINARY | STRING;
s_expr : spec_constant | SYMBOL | KEYWORD | LPAREN s_expr* RPAREN;

/**
 * 3.3 identifiers
 * Indexed removed for simplification
 */
index : NUMERAL | SYMBOL;
identifier : SYMBOL | LPAREN INDEXER SYMBOL index+ RPAREN;

/** 3.4 Attributes */
attribute_value : spec_constant | SYMBOL | LPAREN s_expr* RPAREN;
attribute : KEYWORD attribute_value?;

/**
 * 3.5 Sorts
 */
sort : identifier | LPAREN  identifier sort+ RPAREN;

/**
 * 3.6 Terms
 */
qual_identifier : identifier | LPAREN AS identifier sort RPAREN;
var_binding : LPAREN SYMBOL term RPAREN;
sorted_var : LPAREN SYMBOL sort RPAREN;
term : spec_constant | qual_identifier
    | LPAREN qual_identifier term+ RPAREN
    | LPAREN LET LPAREN var_binding+ RPAREN RPAREN
    | LPAREN FORALL sorted_var+ LPAREN RPAREN RPAREN
    | LPAREN EXISTS sorted_var+ LPAREN RPAREN RPAREN
    | LPAREN ANNOTATION term attribute+ RPAREN
    ;

/**
 * 3.7 Theories
 */
sort_symbol_decl : LPAREN identifier NUMERAL attribute* RPAREN;
meta_spec_constant : TNUMERAL | TDECIMAL | TSTRING;
fun_symbol_decl : LPAREN spec_constant sort attribute* RPAREN
    | LPAREN meta_spec_constant sort attribute* RPAREN
    | LPAREN identifier sort+ attribute* RPAREN
    ;
par_fun_symbol_decl : fun_symbol_decl
    | LPAREN PAR LPAREN SYMBOL+ RPAREN
        LPAREN identifier sort+ attribute* RPAREN RPAREN;
theory_attribute : attribute;
theory_decl : LPAREN 'theory' SYMBOL theory_attribute+ RPAREN;

/**
 * 3.1 Predefined tokens
 * Should be complete w.r.t. SMTLIB, to avoid
 * unparseable inputs
 */
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
