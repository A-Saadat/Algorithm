#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100

// ? k => first Banana Cost 
// ? n => Number Of Bananas 
// ? w => soldier Money

int main (void)
{
    intl k, n, w;
    cin >> k >> n >> w;

    intl cost = 0;
    for(intl i = 1; i <= w; i++){
        cost += k * i;
    }

    if(cost < n)
        cout << 0;
    else
        cout << cost - n;
}