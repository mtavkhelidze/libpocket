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
#include <stdexcept>
#include <utility>

#include "pocket.hxx"


using namespace pocket;

void Fraction::reduce() const
{
    if (_denom == 0) {
        throw std::range_error("Fraction cannot have zero denominator");
    } else if (_num == 0) {
        _denom = 1;
    } else {
        if (_denom < 0) {
            _num = -_num;
            _denom = -_denom;
        }
        int gcd = util::gcd(_num, _denom);
        _num /= gcd;
        _denom /= gcd;
    }
}

Fraction::Fraction(int a, int b) : _num(a), _denom(b)
{
    reduce();
}

Fraction Fraction::reciprocal() const
{
    return {_denom, _num};
}

double Fraction::value() const
{
    return double(_num) / double(_denom);
}

void Fraction::invert() const
{
    std::swap(_num, _denom);
    reduce();
}

