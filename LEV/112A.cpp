#include <bits/stdc++.h>
using namespace std; 

#define intl long long int
     
int main (void)
{

    string a, b;

    cin >> a >> b;

    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] >= 'A' and a[i] <= 'Z')
            a[i] += 32;
        else if(b[i] >= 'A' and b[i] <= 'Z')
            b[i] += 32;
    }

    if (a < b) {
        cout << -1;
    } else if (a > b) {
        cout << 1;
    } else if (a == b) {
        cout << 0;
    }

    
    
}
