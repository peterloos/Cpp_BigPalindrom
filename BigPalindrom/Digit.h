class Digit
{
private:
    int m_digit;

public:
    // c'tors
    Digit ();
    Digit (int digit);

    // getter / setter
    void SetDigit (int digit);
    int GetDigit() const;

    // operators
    friend bool operator== (const Digit&, const Digit&);
    friend bool operator!= (const Digit&, const Digit&);

    // conversion operator
    operator int();
    
    // output
    friend ostream& operator<< (ostream&, const Digit&);
};
