#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int

int main ()
{
    intl n;
    cin >> n;

    if(n % 2 == 0 && n > 2)
        cout << "YES" << endl;
    else    
        cout << "NO" << endl;
}