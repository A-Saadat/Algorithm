#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void)
{
    intl n, m, base = 2;
    cin >> n >> m;
    
    intl sum = 1;
    for(int i = 0; i < n; i++)
    {
        if(m < n){
            cout << m << endl;
            return 0;
        }

        sum *= 2;
    }

    intl ans = m % sum;
    if(sum == m)
        cout << '0' << endl;
    else
        cout << ans << endl;

    // it's not gonna work, i'm just testing. it's the worst way to do Modular Exponentiation :)) -Ali Saadat
}