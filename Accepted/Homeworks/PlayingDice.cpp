#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
 
int main (void)
{

    int a, b;
    cin >> a >> b;


    if (a == b || a - b == 0 || b - a == 0)
    {
        cout << "0 6 0" << endl;
    }
    else if (a - b == 1 && a > b)
    {
        cout << 6 - b << " 0 " << (6 - (6 - b)) << endl;
    }
    else if (a - b == 2 && a > b)
    {
        cout << 7 - a << " 1 " << 6 - (8 - a) << endl;
    } 
    else if (a - b == 3 && a > b)
    {
        cout << 8 - a << " 0 " << 6 - (8 - a) << endl;
    }
    else if (a - b == 4 && a > b) 
    {
        cout << 8 - a << " 1 " << 5 - (8 - a) << endl;
    } 
    else if (a - b == 5 && a > b)
    {
        cout << "3 0 3" << endl;
    }

    else if (b - a == 1 && b > a)
    {
        cout << 6 - (6 - a) << " 0 " << 6 - a << endl;
    }
    else if (b - a == 2 && b > a)
    {
        cout << 6 - (8 - b) << " 1 " << 7 - b << endl;
    }
    else if (b - a == 3 && b > a)
    {
        cout << 6 - (8 - b) << " 0 " << 8 - b << endl;
    }
    else if (b - a == 4 && b > a)
    {
        cout << 5 - (8 - b) << " 1 " << 8 - b << endl;
    }
    else if (b - a == 5 && b > a)
    {
        cout << "3 0 3" << endl;
    }

    return 0;

}