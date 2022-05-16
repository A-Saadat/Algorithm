#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void){
    string a;
    cin >> a;

    if (a[0] >= 'a' and a[0] <= 'z')
        {a[0] -= 32;
        cout << a;}
    else
        cout << a;
}