#include <bits/stdc++.h> 

using namespace std; 

#define intl long long int 

int main (void)
{
    intl a, b;
    cin >> a >> b;

    intl cnt = 0;
    for(int i = 0; i >= 0; i++){
        if(a <= b){
            a *= 3;
            b *= 2;
            cnt++;
        }
        else
            break;
    }

    cout << cnt;
}