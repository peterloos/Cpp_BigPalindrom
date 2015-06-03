#include <iostream>
using namespace std;

#include "Digit.h"
#include "Number.h"

// c'tors / d'tor
Number::Number ()
{
    m_digits = new Digit [1];
    m_count = 1;
}

// user-defined c'tor
Number::Number(char* s)
{
    // count number of digits 
    m_count = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
            m_count ++;

        i ++;
    }

    // allocate array of digit objects
    m_digits = new Digit[m_count];

    // copy digits into array in reverse order
    for (int j = i -1, k = 0; j >= 0; j --)
    {
        if (s[j] >= '0' && s[j] <= '9')
        {
            m_digits[k].SetDigit (s[j] - '0');
            k++;
        }
    }
}

Number::Number (int count)
{
    // allocate array of digit objects
    m_count = count;
    m_digits = new Digit [m_count];
}

Number::Number (const Number& number)
{
    // allocate array of digit objects
    m_digits = new Digit [number.m_count];

    // copy digit objects
    for (int i = 0; i < number.m_count; i ++)
        m_digits[i] = number.m_digits[i];
    m_count = number.m_count;
}

Number::~Number ()
{
    delete[] m_digits;
}

// getter
int Number::Count() const
{
    return m_count;
}

// public interface
bool Number::IsSymmetric () const
{
    for (int i = 0; i < m_count / 2; i ++)
        if (m_digits[i] != m_digits[m_count - 1 - i])
            return false;

    return true;
}

Number Number::Reverse () const
{
    Number tmp (*this);
    for (int i = 0; i < m_count / 2; i ++)
    {
        Digit d = tmp.m_digits[i];
        tmp.m_digits[i] = tmp.m_digits[m_count - 1 - i];
        tmp.m_digits[m_count - 1 - i] = d;
    }
    return tmp;
}

void Number::PrependDigit (const Digit& d)
{
    // allocate new array of digit objects
    Digit* tmp = new Digit [m_count + 1];

    // copy old digits
    for (int i = 0; i < m_count; i ++)
        tmp[i] = m_digits[i];

    // add new digit
    tmp[m_count] = d;

    // switch to new array
    delete[] m_digits;
    m_digits = tmp;
    m_count ++;
}

Number Number::Add (const Number& number) const
{
    int count = (m_count < number.m_count) ? number.m_count : m_count;
    Number result (count);

    int carry = 0;
    for (int pos = 0; pos < count; pos ++)
    {
        int sum1 = (pos < m_count) ? m_digits[pos].GetDigit() : 0;
        int sum2 = (pos < number.m_count) ? number.m_digits[pos].GetDigit() : 0;
        int sum = sum1 + sum2 + carry;

        if (sum >= 10)
        {
            sum -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        Digit d (sum);
        result.m_digits[pos] = d;
    }

    if (carry == 1)
    {
        Digit d (1);
        result.PrependDigit (d);
    } 

    return result;
}

Number operator+ (const Number& number1, const Number& number2)
{
    return number1.Add (number2);
}

// assignment operator
Number& Number::operator= (const Number& number)
{
    if (this != &number)
    {
        // release left side
        delete[] m_digits;

        // allocate array of digit objects
        m_digits = new Digit [number.m_count];
        for (int i = 0; i < number.m_count; i ++)
            m_digits[i] = number.m_digits[i];
        m_count = number.m_count;
    }

    return *this;
}

// index operator (read-only)
int Number::operator[] (int i) const
{
    return (i >= 0 && i < m_count) ? m_digits[i].GetDigit() : 0;
}

// comparison operators
bool operator== (const Number& number1, const Number& number2)
{
    if (number1.m_count != number2.m_count)
        return false;

    for (int i = 0; i < number1.m_count; i ++)
        if (number1.m_digits[i] != number2.m_digits[i])
            return false;

    return true;
}

bool operator!= (const Number& number1, const Number& number2)
{
    return ! (number1 == number2);
}

// output
ostream& operator<< (ostream& os, const Number& number)
{
    for (int i = number.m_count - 1; i >= 0; i --)
        os << number.m_digits[i];

    return os;
}
