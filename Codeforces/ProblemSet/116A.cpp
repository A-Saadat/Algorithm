#include <bits/stdc++.h> 

using namespace std; 

#define intl long long int 
#define def 1000

int main (void)
{
    intl n;
    cin >> n;

    intl a[def], b[def];
    for (intl i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    
    intl maxAns = 0, currentAns = b[0];
    for (intl i = 1; i < n; i++){
        if(currentAns > maxAns)
            maxAns = currentAns;

        currentAns += b[i];
        currentAns -= a[i];
    }

    cout << maxAns;
}