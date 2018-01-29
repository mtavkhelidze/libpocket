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


using namespace pocket::util;

TEST(util_gcd, a_equals_b)
{
    EXPECT_EQ(gcd(13, 13), 13);
}

TEST(util_gcd, a_is_a_prime)
{
    EXPECT_EQ(gcd(37, 600), 1);
}

TEST(util_gcd, straight_case)
{
    EXPECT_EQ(gcd(624129, 2061517), 18913);
}

TEST(util_gcd, a_is_negative)
{
    EXPECT_EQ(gcd(-20, 10), 10);
}

TEST(util_gcd, b_is_negative)
{
    EXPECT_EQ(gcd(100, -30), 10);
}

TEST(util_gcd, a_and_b_are_negative)
{
    EXPECT_EQ(gcd(-200, -80), 40);
}
