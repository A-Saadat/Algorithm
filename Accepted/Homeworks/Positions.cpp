#include <bits/stdc++.h>

using namespace std; 

#define intl long long int
     
int main (void)
{
    intl n, a, b;
    cin >> n >> a >> b;

    cout << min(b + 1, n - a) << endl;
}


