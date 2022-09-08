#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100

int main (void)
{
    intl n;
    cin >> n;

    intl x[def], y[def], z[def];
    for(intl i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> z[i];
    }

    intl xRes = 0, yRes = 0, zRes = 0;
    for(intl i = 0; i < n; i++){
        xRes += x[i];
        yRes += y[i];
        zRes += z[i];
    }

    // cout << "x = " << xRes << ", " << "y = " << yRes << ", " << "z = " << zRes << ", ";

    if(xRes != 0 or xRes != 0 or xRes != 0)
        cout << "NO";
    else
        cout << "YES";
    

}