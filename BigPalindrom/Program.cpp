#include <iostream>
using namespace std;

#include "Digit.h"
#include "Number.h"
#include "PalindromResult.h"
#include "Palindrom.h"

// test functions (prototypes)
void Test00();
void Test01();
void Test02();

void Test10();
void Test11();
void Test12();
void Test13();
void Test14();
void Test15();

void Test20();
void Test21();
void Test22();
void Test23();
void Test24();
void Test25();
void Test26();
void Test27();

void Test30();

void main()
{
    Test00();
    Test01();
    Test02();
    Test10();
    Test11();
    Test12();
    Test13();
    Test14();
    Test15();
    Test20();
    Test21();
    Test22();
    Test23();
    Test24();
    Test25();
    Test26();
    Test27();
    Test30();

	getchar();
}

void Test00 ()
{
    Digit d;
    cout << d << endl;

    Digit d1 (5);
    cout << d1 << endl;

    Digit d2 (15);
    cout << d2 << endl;
}

void Test01 ()
{
    Digit d1(1);
    Digit d2(2);
    cout << (d1 == d2) << endl;
    cout << (d1 != d2) << endl;
}

void Test02 ()
{
    Digit d(5);
    int n = d;
    cout << n << endl;
}

void Test10 ()
{
    Number n("123.456.789");
    cout << "Number: " << n << endl;
    cout << "Digits: " << n.Count() << endl;
}

void Test11 ()
{
    Number n1 ("1234321");
    cout << n1.IsSymmetric() << endl;

    Number n2 ("1234322");
    cout << n2.IsSymmetric() << endl;
}

void Test12 ()
{
    Number n ("123456789");
    Number m = n.Reverse();
    cout << n << endl;
    cout << m << endl;
}

void Test13()
{
    Number n ("12345");

    for (int i = 0; i < n.Count(); i ++)
        cout << "found: " << n[i] << endl;
}

void Test14 ()
{
    Number n ("123");
    cout << n << endl;

    Digit d (4);
    n.PrependDigit (d);
    cout << n << endl;

    d = 5;
    n.PrependDigit (d);
    cout << n << endl;
}

void Test15 ()
{
    Number n1 ("1282");
    Number n2 ("976");
    Number n3 = n1.Add (n2);
    cout << n1 << '+' << n2 << '=' << n3 << endl;

    n1 = "99999999";
    n2 = "1";
    n3 = n1.Add (n2);
    cout << n1 << '+' << n2 << '=' << n3 << endl;
    cout << n3 << endl;
}

void Test20 ()
{
    Palindrom p;
    p.SetStart (Number ("165"));
    p.SetSteps (10);
    PalindromResult r = p.CalcPalindrom ();
    cout << r << endl;
}

void Test21 ()
{
    // 89 -> 25 steps
    Palindrom p;
    p.SetStart (Number ("89"));
    p.SetSteps (90);
    PalindromResult r = p.CalcPalindrom ();
    cout << r << endl;
}

void Test22 ()
{
    // 53978 -> 8 steps
    Palindrom p;
    p.SetStart (Number ("53978"));
    p.SetSteps (10);
    PalindromResult r = p.CalcPalindrom ();
    cout << r << endl;
}

void Test23 ()
{
    // 10911 -> 55 steps
    Palindrom p;
    p.SetStart (Number ("10911"));
    p.SetSteps (60);
    PalindromResult r = p.CalcPalindrom ();
    cout << r << endl;
}

void Test24 ()
{
    // 107000020928910 -> 192 steps
    Palindrom p;
    p.SetStart (Number ("107000020928910"));
    p.SetSteps (200);
    PalindromResult r = p.CalcPalindrom ();
    cout << r << endl;
}

void Test25()
{
    // '196' problem, no palindrom found !
    Palindrom p;
    p.SetStart (Number ("196"));
    p.SetSteps (2000);
    cout << "Searching palindrom:" << endl << "Start value = " << p.GetStart() << endl;
    PalindromResult r = p.CalcPalindrom ();
    cout << r << endl;
}

void Test26 ()
{
    // 107000020928910 -> 192 steps
    Palindrom p;
    Number start ("107.000.020.928.910");
    p.CalcPalindromVerbose (cout, start, 200);
}

void Test27 ()
{
    // 10911 -> 55 steps
    Palindrom p;
    Number start ("10911");
    p.CalcPalindromVerbose (cout, start, 60);
}

void Test30 ()
{
    // Fourth Euler problem
    int i = 1, j = 1;
    int candidate = 1;

    for (int n = 111; n < 999; n++)
    {
        for (int m = 111; m < 999; m++)
        {
            if (n < m)
            {
                int prod = n * m;

                char buffer [32];
                _itoa_s (prod, buffer, 10);
                Number num (buffer);

                if (num.IsSymmetric())
                {
                    if (prod > candidate)
                    {
                        i = n;
                        j = m;
                        candidate = i * j;
                    }
                }
            }
        }
    }

    cout << "Solution of fourth Euler problem:" << endl;
    cout << i << " * " << j << " = " << i*j << endl;
}

