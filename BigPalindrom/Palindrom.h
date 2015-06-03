class Palindrom
{
private:
    Number m_start;
    int m_steps;

public:
    // c'tors / d'tor
    Palindrom ();
    Palindrom (int);

    // getter / setter
    void SetStart (const Number&);
    Number GetStart () const;
    void SetSteps (int);
    int GetSteps () const;

    // public interface
    PalindromResult CalcPalindrom ();
    PalindromResult CalcPalindrom (const Number&);

    // verbose interface
    void CalcPalindromVerbose (ostream&, const Number&, int);
};
