#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 1000000

int main (void)
{
    intl a[4], d;
    for(intl i = 0; i < 4; i++)
        cin >> a[i];
    

    cin >> d;

    for(intl i = 0; i < 4; i++){
        if(a[i] == 1){
            cout << d;
            return 0;
        }
    }


    bool isAvail[def];

    for(intl i = 0; i < 4; i++){

        intl n  = d / a[i], j = 1, idx = 0;
        for(; j < d; j){
            idx++;
            j = a[i] * idx;
            isAvail[j] = true;
        }

    }

    intl cnt = 0;
    for(intl i = 1; i <= d; i++){
        if(isAvail[i])
            cnt++;
    }

    cout << cnt;
}