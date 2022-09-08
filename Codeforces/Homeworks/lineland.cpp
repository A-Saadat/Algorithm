#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
#define def 100


int main (void){

    intl n;
    cin >> n;

    intl a[100001];

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    cout << a[2] - a[1]  << " " << a[n] - a[1] << endl;

    for(int i = 2; i < n; i++)
    {
        cout << min(a[i + 1] - a[i], a[i] - a[i - 1]) << " " << max(a[n] - a[i], a[i] - a[1]) << endl;
    }

    cout << a[n] - a[n - 1] << " " << a[n] - a[1] << endl;




}