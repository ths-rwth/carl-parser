//
// Created by Sebastian Junges on 28/06/2017.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "carl-parser/Parser.h"

using namespace carlparser;

TEST_CASE("testing the parse") {
    auto res = carlparser::deserialize<carl::MultivariatePolynomial<mpq_class>>("(/ 12 12)");
    DOCTEST_CHECK_EQ(check_type(res), carlparser::ParserReturnType::Rational);
    res = carlparser::deserialize<carl::MultivariatePolynomial<mpq_class>>("x");
    DOCTEST_CHECK_EQ(check_type(res), carlparser::ParserReturnType::Variable);
    res = carlparser::deserialize<carl::MultivariatePolynomial<mpq_class>>("(+ x 1)");
    DOCTEST_CHECK_EQ(check_type(res), carlparser::ParserReturnType::Polynomial);
    res = carlparser::deserialize<carl::MultivariatePolynomial<mpq_class>>("(< x 1)");
    DOCTEST_CHECK_EQ(check_type(res), carlparser::ParserReturnType::Constraint);
}