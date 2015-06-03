#include <iostream>
using namespace std;

class PalindromResult
{
private:
    Number m_result;
    Number m_start;
    int m_steps;

public:
    // c'tors
    PalindromResult ();
    PalindromResult (const Number& result, const Number& start, int);

    // getter
    Number GetResult () const { return m_result; }
    Number GetStart () const { return m_start; }
    int GetSteps () const { return m_steps; }

    // output
    friend ostream& operator<< (ostream&, const PalindromResult&);
};
