/**
 * Copyright (c) 2018 Misha Tavkhelidze <misha.tavkhelidze@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
*/

#include <gtest/gtest.h>

#include "pocket.hxx"


using namespace pocket;

TEST(Fraction_constructor, reduces_fraction_to_simplest_terms)
{
    const Fraction f(20, 100);
    EXPECT_EQ(f.num(), 1);
    EXPECT_EQ(f.denom(), 5);
}

TEST(Fraction_constructor, trows_range_error_if_denominator_is_zero)
{
    EXPECT_THROW(new Fraction(10, 0), std::range_error);
}

TEST(Fraction_reciprocal, returns_b_by_a)
{
    const Fraction f(3, 5);
    const Fraction r = f.reciprocal();
    EXPECT_EQ(r.num(), f.denom());
    EXPECT_EQ(r.denom(), f.num());
}

TEST(Fraction_value, returns_double_decimal)
{
    const Fraction f(2, 10);
    EXPECT_EQ(f.value(), 0.2);
}

TEST(Fraction_invert, swaps_numerator_and_denominator)
{
    const Fraction f(13, 17);
    f.invert();
    EXPECT_EQ(f.num(), 17);
    EXPECT_EQ(f.denom(), 13);
}

TEST(Fraction_invert, throws_exception_when_numerator_is_zero)
{
    const Fraction f(0, 17);
    EXPECT_THROW(f.invert(), std::range_error);
}

TEST(Fraction_plus_equals, returns_reduced_sum)
{
    Fraction f1(7, 5), f2(7, 5);
    f1 += f2;
    EXPECT_EQ(f1.num(), 14);
    EXPECT_EQ(f1.denom(), 5);
}

TEST(Fraction_mult_equals, returns_reduced_multiple)
{
    Fraction f1(3, 4), f2(2, 5);
    f1 *= f2;
    EXPECT_EQ(f1.num(), 3);
    EXPECT_EQ(f1.denom(), 10);
}
