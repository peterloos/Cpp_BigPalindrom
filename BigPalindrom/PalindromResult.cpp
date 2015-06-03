#include <iostream>
using namespace std;

#include "Digit.h"
#include "Number.h"
#include "PalindromResult.h"

PalindromResult::PalindromResult () : m_result(), m_start()
{
    m_steps = -1;
}

PalindromResult::PalindromResult (const Number& result, const Number& start, int steps)
{
    m_result = result;
    m_start = start;
    m_steps = steps;
}

ostream& operator<< (ostream& os, const PalindromResult& result)
{
    if (result.m_steps >= 0)
        os << "Palindrom: " << result.m_result << endl
           << "[Start: " << result.m_start
           << ", " << result.m_steps << " steps]";
    else
        os << "No Palindrom found!" << endl;

    return os;
}

