
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/smtlib.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "smtlibParser.h"


namespace carlparser {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by smtlibParser.
 */
class  smtlibVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by smtlibParser.
   */
    virtual antlrcpp::Any visitSpec_constant(smtlibParser::Spec_constantContext *context) = 0;

    virtual antlrcpp::Any visitS_expr(smtlibParser::S_exprContext *context) = 0;

    virtual antlrcpp::Any visitIndex(smtlibParser::IndexContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(smtlibParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitAttribute_value(smtlibParser::Attribute_valueContext *context) = 0;

    virtual antlrcpp::Any visitAttribute(smtlibParser::AttributeContext *context) = 0;

    virtual antlrcpp::Any visitSort(smtlibParser::SortContext *context) = 0;

    virtual antlrcpp::Any visitQual_identifier(smtlibParser::Qual_identifierContext *context) = 0;

    virtual antlrcpp::Any visitVar_binding(smtlibParser::Var_bindingContext *context) = 0;

    virtual antlrcpp::Any visitSorted_var(smtlibParser::Sorted_varContext *context) = 0;

    virtual antlrcpp::Any visitTerm(smtlibParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitSort_symbol_decl(smtlibParser::Sort_symbol_declContext *context) = 0;

    virtual antlrcpp::Any visitMeta_spec_constant(smtlibParser::Meta_spec_constantContext *context) = 0;

    virtual antlrcpp::Any visitFun_symbol_decl(smtlibParser::Fun_symbol_declContext *context) = 0;

    virtual antlrcpp::Any visitPar_fun_symbol_decl(smtlibParser::Par_fun_symbol_declContext *context) = 0;

    virtual antlrcpp::Any visitTheory_attribute(smtlibParser::Theory_attributeContext *context) = 0;

    virtual antlrcpp::Any visitTheory_decl(smtlibParser::Theory_declContext *context) = 0;


};

}  // namespace carlparser
