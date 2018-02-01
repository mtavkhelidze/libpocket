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

#ifndef LIB_POCKET_HXX
#define LIB_POCKET_HXX

#include <iostream>


namespace pocket {
    namespace util {
        int gcd(int a, int b);
    }

    class Fraction {
    private:
        mutable int _p;
        mutable int _q;

        void reduce() const;

    public:
        Fraction(int a = 0, int b = 1);

        int p() const
        {
            return _p;
        };

        int q() const
        {
            return _q;
        };

        double value() const;
        void invert() const;

        Fraction reciprocal() const;

        Fraction &operator +=(const Fraction &other);
        Fraction &operator *=(const Fraction &other);
        Fraction &operator -=(const Fraction &other);
        Fraction &operator /=(const Fraction &other);

        Fraction operator +(const Fraction &a);
        Fraction operator -(const Fraction &a);

        Fraction operator *(const Fraction &other);
        Fraction operator /(const Fraction &other);

        bool operator ==(const Fraction &other);
        bool operator !=(const Fraction &other);
        bool operator <(const Fraction &other);
        bool operator <=(const Fraction &other);
        bool operator >(const Fraction &other);
        bool operator >=(const Fraction &other);

        friend std::ostream& operator << (std::ostream& out, const Fraction& f);
    };


    std::ostream &operator <<(std::ostream &out, const Fraction &f);
};
#endif // LIB_POCKET_HXX
