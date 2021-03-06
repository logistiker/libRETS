/*
 * Copyright (C) 2005 National Association of REALTORS(R)
 *
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, and/or sell copies of the
 * Software, and to permit persons to whom the Software is furnished
 * to do so, provided that the above copyright notice(s) and this
 * permission notice appear in all copies of the Software and that
 * both the above copyright notice(s) and this permission notice
 * appear in supporting documentation.
 */
#include <cppunit/extensions/HelperMacros.h>
#include "testUtil.h"
#include "librets/sql_forward.h"
#include "librets/GtCriterion.h"
#include "librets/LiteralCriterion.h"
#include "librets/DmqlExpression.h"

using namespace librets;
using namespace librets::DmqlExpression;
using namespace std;

#define CLASS GtCriterionTest

class CLASS : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(CLASS);
    CPPUNIT_TEST(testEquals);
    CPPUNIT_TEST(testToDmql);
    CPPUNIT_TEST(testDmqlExpression);
    CPPUNIT_TEST_SUITE_END();

  protected:
    void testEquals();
    void testToDmql();
    void testDmqlExpression();
};

CPPUNIT_TEST_SUITE_REGISTRATION(CLASS);

void CLASS::testEquals()
{
    LiteralCriterionPtr foo(new LiteralCriterion("foo"));
    LiteralCriterionPtr bar(new LiteralCriterion("bar"));
    GtCriterion gt1("field1", foo);
    GtCriterion gt2("field1", foo);
    GtCriterion gt3("field1", bar);
    GtCriterion gt4("field2", foo);
    GtCriterion gt5("field2", bar);

    ASSERT_EQUAL(gt1, gt2);
    ASSERT_NOT_EQUAL(gt1, gt3);
    ASSERT_NOT_EQUAL(gt1, gt4);
    ASSERT_NOT_EQUAL(gt1, gt5);
    ASSERT_NOT_EQUAL(gt3, gt4);
    ASSERT_NOT_EQUAL(gt3, gt5);
}

void CLASS::testToDmql()
{
    LiteralCriterionPtr one(new LiteralCriterion("1"));
    GtCriterion gt("field", one);
    ASSERT_STRING_EQUAL("(field=1+)", gt.ToDmqlString());
}

void CLASS::testDmqlExpression()
{
    DmqlCriterionPtr c1 = gt("field1", literal("1"));
    DmqlCriterionPtr c2 = gt("field1", literal(1));
    DmqlCriterionPtr c3 = gt("field1", literal("2"));

    ASSERT_EQUAL(*c1, *c2);
    ASSERT_NOT_EQUAL(*c1, *c3);
}
