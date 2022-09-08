#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
 
int main (void)
{
    intl s1, s2, s3, s4, a, b, c, d, x, y;
    cin >> s1 >> s2 >> s3 >> s4;
    x = 0;
    y = 1;


    if(s1 != s2 && s1 != s3 && s1 != s4)
    {
        y += 1;
    }
    if(s2 != s3 && s2 != s4)
    {
        y += 1;
    }
    if(s3 != s4)
    {
        y += 1;
    }
    x = (4 - y);
    cout << x << endl;

    

    return 0;

}

// if (s1 != s2 || s1 != s3 || s1 != s4)
    // {
    //     a = 0;
    // } 
    // else if (s1 == s2 || s1 == s3 || s1 == s4)
    // {
    //     a = 1;
    // }
    // else if (s2 != s1 || s2 != s3 || s2 != s4)
    // {
    //     b = 0;
    // }
    // else if (s2 == s1 || s2 == s3 || s2 == s4)
    // {
    //     b = 1;
    // }
    // else if (s3 != s1 || s3 != s2 || s3 != s4)
    // {
    //     c = 0;
    // }
    // else if (s3 == s1 || s2 || s4)
    // {
    //     c = 1;
    // }
    // else if (s4 != s1 || s4 != s2 || s4 != s3)
    // {
    //     d = 0;
    // }
    // else if (s4 == s1 || s4 == s2 || s4 == s3)
    // {
    //     d = 1;
    // }

    // cout << c << endl;