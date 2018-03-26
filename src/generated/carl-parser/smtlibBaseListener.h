
// Generated from /home/travis/build/smtrat/carl-parser/src/carl-parser/smtlib.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "smtlibListener.h"


namespace carlparser {

/**
 * This class provides an empty implementation of smtlibListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  smtlibBaseListener : public smtlibListener {
public:

  virtual void enterSpec_constant(smtlibParser::Spec_constantContext * /*ctx*/) override { }
  virtual void exitSpec_constant(smtlibParser::Spec_constantContext * /*ctx*/) override { }

  virtual void enterS_expr(smtlibParser::S_exprContext * /*ctx*/) override { }
  virtual void exitS_expr(smtlibParser::S_exprContext * /*ctx*/) override { }

  virtual void enterIndex(smtlibParser::IndexContext * /*ctx*/) override { }
  virtual void exitIndex(smtlibParser::IndexContext * /*ctx*/) override { }

  virtual void enterIdentifier(smtlibParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(smtlibParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterAttribute_value(smtlibParser::Attribute_valueContext * /*ctx*/) override { }
  virtual void exitAttribute_value(smtlibParser::Attribute_valueContext * /*ctx*/) override { }

  virtual void enterAttribute(smtlibParser::AttributeContext * /*ctx*/) override { }
  virtual void exitAttribute(smtlibParser::AttributeContext * /*ctx*/) override { }

  virtual void enterSort(smtlibParser::SortContext * /*ctx*/) override { }
  virtual void exitSort(smtlibParser::SortContext * /*ctx*/) override { }

  virtual void enterQual_identifier(smtlibParser::Qual_identifierContext * /*ctx*/) override { }
  virtual void exitQual_identifier(smtlibParser::Qual_identifierContext * /*ctx*/) override { }

  virtual void enterVar_binding(smtlibParser::Var_bindingContext * /*ctx*/) override { }
  virtual void exitVar_binding(smtlibParser::Var_bindingContext * /*ctx*/) override { }

  virtual void enterSorted_var(smtlibParser::Sorted_varContext * /*ctx*/) override { }
  virtual void exitSorted_var(smtlibParser::Sorted_varContext * /*ctx*/) override { }

  virtual void enterTerm(smtlibParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(smtlibParser::TermContext * /*ctx*/) override { }

  virtual void enterSort_symbol_decl(smtlibParser::Sort_symbol_declContext * /*ctx*/) override { }
  virtual void exitSort_symbol_decl(smtlibParser::Sort_symbol_declContext * /*ctx*/) override { }

  virtual void enterMeta_spec_constant(smtlibParser::Meta_spec_constantContext * /*ctx*/) override { }
  virtual void exitMeta_spec_constant(smtlibParser::Meta_spec_constantContext * /*ctx*/) override { }

  virtual void enterFun_symbol_decl(smtlibParser::Fun_symbol_declContext * /*ctx*/) override { }
  virtual void exitFun_symbol_decl(smtlibParser::Fun_symbol_declContext * /*ctx*/) override { }

  virtual void enterPar_fun_symbol_decl(smtlibParser::Par_fun_symbol_declContext * /*ctx*/) override { }
  virtual void exitPar_fun_symbol_decl(smtlibParser::Par_fun_symbol_declContext * /*ctx*/) override { }

  virtual void enterTheory_attribute(smtlibParser::Theory_attributeContext * /*ctx*/) override { }
  virtual void exitTheory_attribute(smtlibParser::Theory_attributeContext * /*ctx*/) override { }

  virtual void enterTheory_decl(smtlibParser::Theory_declContext * /*ctx*/) override { }
  virtual void exitTheory_decl(smtlibParser::Theory_declContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace carlparser
