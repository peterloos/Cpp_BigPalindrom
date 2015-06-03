#include <iostream>
using namespace std;

#include "Digit.h"

// c'tors
Digit::Digit ()
{
    m_digit = 0;
}

Digit::Digit (int digit)
{
    m_digit = (digit >= 0 && digit <= 9) ? digit : 0;
}

// getter / setter
void Digit::SetDigit (int digit)
{
    m_digit = (digit >= 0 && digit <= 9) ? digit : 0;
}

int Digit::GetDigit() const
{
    return m_digit;
}

// operators
bool operator== (const Digit& d1, const Digit& d2)
{
    return d1.m_digit == d2.m_digit;
}

bool operator!= (const Digit& d1, const Digit& d2)
{
    return d1.m_digit != d2.m_digit;
}

// conversion operator
Digit::operator int()
{
	return m_digit;
}

// output
ostream& operator<< (ostream& os, const Digit& digit)
{
    os << digit.m_digit;
    return os;
}