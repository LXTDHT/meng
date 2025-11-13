#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
public:
    Fraction(); // default constructor
    virtual ~Fraction();

    Fraction(int n = 0);
    Fraction(int n = 0, int d = 1);

    int numerator() const;
    int denominator() const;
    Fraction reciprocal() const;

    void invert();

    // operator overloading
    friend Fraction operator + (const Fraction& x, const Fraction& y);
    friend Fraction operator - (const Fraction& x, const Fraction& y);
    friend Fraction operator * (const Fraction& x, const Fraction& y);
    friend Fraction operator / (const Fraction& x, const Fraction& y);
};

inline Fraction operator * (const Fraction& x, const Fraction& y) {
    return Fraction(x.numerator() * y.numerator(), x.denominator() * y.denominator());
}

#endif