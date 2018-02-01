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
    if (_q == 0) {
        throw std::range_error("Fraction cannot have zero denominator");
    } else if (_p == 0) {
        _q = 1;
    } else {
        if (_q < 0) {
            _p = -_p;
            _q = -_q;
        }
        int gcd = util::gcd(_p, _q);
        _p /= gcd;
        _q /= gcd;
    }
}

Fraction::Fraction(int a, int b) : _p(a), _q(b)
{
    reduce();
}

void Fraction::invert() const
{
    std::swap(_p, _q);
    reduce();
}

double Fraction::value() const
{
    return double(_p) / double(_q);
}

Fraction Fraction::reciprocal() const
{
    return { _q, _p };
}

Fraction &Fraction::operator +=(const Fraction &other)
{
    _p = _p * other._q + _q * other._p;
    _q = _q * other._q;
    reduce();
    return *this;
}

Fraction &Fraction::operator *=(const Fraction &other)
{
    _p = _p * other.p();
    _q = _q * other.q();
    reduce();
    return *this;
}

Fraction &Fraction::operator -=(const Fraction &other)
{
    _p = _p * other.q() - other.p() * _q;
    _q = _q * other.q();
    reduce();
    return *this;
}

Fraction &Fraction::operator /=(const Fraction &other)
{
    _p = _p * other.q();
    _q = _q * other.p();
    reduce();
    return *this;
}

Fraction Fraction::operator +(const Fraction &other)
{
    Fraction r = *this;
    return r += other;
}

Fraction Fraction::operator -(const Fraction &other)
{
    Fraction r = *this;
    return r -= other;
}

Fraction Fraction::operator *(const Fraction &other)
{
    Fraction r = *this;
    return r *= other;
}

Fraction Fraction::operator /(const Fraction &other)
{
    Fraction r = *this;
    return r /= other;
}
