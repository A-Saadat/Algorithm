#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void)
{   
    intl n;
    cin >> n;
    if(n == 1)
        cout << "1 1" << endl;
    else
        cout << n - 1 << " " << n << endl;
}