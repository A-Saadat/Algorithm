#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 1000000

int main (void)
{
    intl n;
    cin >> n;
    char ans[def];

    for(int i = 0; i < n; i++)
        ans[i] = 'a';
    
    for(int i = 2; i < n; i += 4){
        ans[i] = 'b';

        if(i + 1 < n)
            ans[i + 1] = 'b';
    }

    cout << ans;
}