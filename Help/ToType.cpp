#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
#define def 10000

int main (void)
{
    // cout << (char) 98 << endl;

    // char c;

    // cin >> c;

    // int a = (int) c + 1;

    // cout << (char) a << endl;

    // char c;

    // cin >> c;

    // int a = (int) c - 32;

    // cout << (char) a;

    // char c;

    // cin >> c;
    
    // cout << (int) c - 'a' + 1 << endl; // you can also type 96 

    // string a;
    // cin >> a;
    // cout << a << endl << a.size();

    string a;

    cin >> a;
    
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i] >= 'A' and a[i] <= 'Z')
        {
            a[i] = a[i] + 32;
        }

    }
     
    cout << a;




}