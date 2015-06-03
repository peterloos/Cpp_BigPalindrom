#include <iostream>
using namespace std;

#include "Digit.h"
#include "Number.h"
#include "PalindromResult.h"
#include "Palindrom.h"

// c'tors
Palindrom::Palindrom () : m_steps(0), m_start("1")
{
}

Palindrom::Palindrom (int steps) : m_steps(steps), m_start("1")
{
}

// getter / setter
void Palindrom::SetStart (const Number& start)
{
    m_start = start;
}

Number Palindrom::GetStart () const
{
    return m_start;
}

void Palindrom::SetSteps (int steps)
{
    m_steps = steps;
}

int Palindrom::GetSteps () const
{
    return m_steps;
}

// public interface
PalindromResult Palindrom::CalcPalindrom ()
{
    return CalcPalindrom(m_start);
}

PalindromResult Palindrom::CalcPalindrom (const Number& number)
{
    m_start = number;
    Number n = m_start;
    for (int i = 0; i < m_steps; i ++)
    {
        if (n.IsSymmetric ())
            return PalindromResult (n, m_start, i+1);

        Number m = n.Reverse ();
        n = n.Add (m);
    }

    return PalindromResult();
}

void Palindrom::CalcPalindromVerbose (ostream& os, const Number& number, int steps)
{
    m_start = number;
    Number n = m_start;
    PalindromResult result;
    os << "Start: " << n << endl;
    for (int i = 0; i < steps; i ++)
    {
        if (n.IsSymmetric ())
        {
            result = PalindromResult (n, m_start, i);
            break;
        }

        Number m = n.Reverse ();
        n = n.Add (m);
        os << "Next:  " << n << endl;
    }

    os << endl << result << endl;
}

