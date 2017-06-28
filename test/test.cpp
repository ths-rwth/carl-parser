//
// Created by Sebastian Junges on 28/06/2017.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <antlr4-runtime.h>
#include <tree/ParseTreeVisitor.h>
#include "SerializationLexer.h"
#include "SerializationParser.h"
#include "SerializationVisitor.h"
#include "ParseTreeVisitor.h"

using namespace carlparser;
using namespace antlr4;

TEST_CASE("testing the parse") {
    ANTLRInputStream input(u8"(/ + 12 12)");
    SerializationLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();

    SerializationParser parser(&tokens);
    tree::ParseTree* tree = parser.start();
    ParseTreeVisitor<carl::MultivariatePolynomial<mpq_class>> visitor;
    tree->accept(&visitor);
}