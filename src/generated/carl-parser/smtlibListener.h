
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/smtlib.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "smtlibParser.h"


namespace carlparser {

/**
 * This interface defines an abstract listener for a parse tree produced by smtlibParser.
 */
class  smtlibListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSpec_constant(smtlibParser::Spec_constantContext *ctx) = 0;
  virtual void exitSpec_constant(smtlibParser::Spec_constantContext *ctx) = 0;

  virtual void enterS_expr(smtlibParser::S_exprContext *ctx) = 0;
  virtual void exitS_expr(smtlibParser::S_exprContext *ctx) = 0;

  virtual void enterIndex(smtlibParser::IndexContext *ctx) = 0;
  virtual void exitIndex(smtlibParser::IndexContext *ctx) = 0;

  virtual void enterIdentifier(smtlibParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(smtlibParser::IdentifierContext *ctx) = 0;

  virtual void enterAttribute_value(smtlibParser::Attribute_valueContext *ctx) = 0;
  virtual void exitAttribute_value(smtlibParser::Attribute_valueContext *ctx) = 0;

  virtual void enterAttribute(smtlibParser::AttributeContext *ctx) = 0;
  virtual void exitAttribute(smtlibParser::AttributeContext *ctx) = 0;

  virtual void enterSort(smtlibParser::SortContext *ctx) = 0;
  virtual void exitSort(smtlibParser::SortContext *ctx) = 0;

  virtual void enterQual_identifier(smtlibParser::Qual_identifierContext *ctx) = 0;
  virtual void exitQual_identifier(smtlibParser::Qual_identifierContext *ctx) = 0;

  virtual void enterVar_binding(smtlibParser::Var_bindingContext *ctx) = 0;
  virtual void exitVar_binding(smtlibParser::Var_bindingContext *ctx) = 0;

  virtual void enterSorted_var(smtlibParser::Sorted_varContext *ctx) = 0;
  virtual void exitSorted_var(smtlibParser::Sorted_varContext *ctx) = 0;

  virtual void enterTerm(smtlibParser::TermContext *ctx) = 0;
  virtual void exitTerm(smtlibParser::TermContext *ctx) = 0;

  virtual void enterSort_symbol_decl(smtlibParser::Sort_symbol_declContext *ctx) = 0;
  virtual void exitSort_symbol_decl(smtlibParser::Sort_symbol_declContext *ctx) = 0;

  virtual void enterMeta_spec_constant(smtlibParser::Meta_spec_constantContext *ctx) = 0;
  virtual void exitMeta_spec_constant(smtlibParser::Meta_spec_constantContext *ctx) = 0;

  virtual void enterFun_symbol_decl(smtlibParser::Fun_symbol_declContext *ctx) = 0;
  virtual void exitFun_symbol_decl(smtlibParser::Fun_symbol_declContext *ctx) = 0;

  virtual void enterPar_fun_symbol_decl(smtlibParser::Par_fun_symbol_declContext *ctx) = 0;
  virtual void exitPar_fun_symbol_decl(smtlibParser::Par_fun_symbol_declContext *ctx) = 0;

  virtual void enterTheory_attribute(smtlibParser::Theory_attributeContext *ctx) = 0;
  virtual void exitTheory_attribute(smtlibParser::Theory_attributeContext *ctx) = 0;

  virtual void enterTheory_decl(smtlibParser::Theory_declContext *ctx) = 0;
  virtual void exitTheory_decl(smtlibParser::Theory_declContext *ctx) = 0;


};

}  // namespace carlparser
