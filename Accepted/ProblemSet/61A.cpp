#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100000

int main (void)
{
    string a, b;
    cin >> a >> b;

    char ans[def];
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i])
            ans[i] = '0';
        else
            ans[i] = '1';
    }
    
    for(int i = 0; i < a.size(); i++){
        cout << ans[i];
    }
}