class Number
{
private:
    Digit* m_digits;         // array of 'Digit' objects
    int    m_count;          // number of 'Digit' objects

public:
    // c'tors / d'tor
    Number ();               // default c'tor
    Number (char*);          // conversion c'tor
    Number (const Number&);  // copy c'tor
    ~Number ();              // d'tor

private:
    Number (int count);      // private user-defined c'tor

public:
    // getter
    int Count() const;

    // public interface
    bool IsSymmetric () const;
    Number Reverse () const;
    void PrependDigit (const Digit&);
    Number Add (const Number&) const;

    // assignment operator
    Number& operator= (const Number&);

    // index operator (read-only)
    int operator[] (int i) const;

    // operators
    friend bool operator== (const Number&, const Number&);
    friend bool operator!= (const Number&, const Number&);
    friend Number operator+ (const Number&, const Number&);

    // output
    friend ostream& operator<< (ostream&, const Number&);
};
