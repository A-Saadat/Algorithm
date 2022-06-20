#include <bits/stdc++.h> 

using namespace std; 

#define intl long long int 

int main (void)
{
    intl n, amount;
    cin >> n >> amount;

    for(intl i = 0; i < amount; i++){
        if(n % 10 == 0)
            n /= 10;
        else
            n--;
    }

    cout << n;
}