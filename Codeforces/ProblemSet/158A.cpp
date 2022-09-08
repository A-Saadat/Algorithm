#include <bits/stdc++.h>

using namespace std; 

#define intl long long int
#define def 10000
     
int main (void)
{
    intl n, k, a[def];
    cin >> n >> k;
    intl zeroCnt = 0;

    for(intl i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0)
            zeroCnt++;
    }
    if(a[k] > a[k + 1]){
        cout << k;
        return 0;
    } 
    else if(a[k] == 0){
        cout << n - zeroCnt << endl;
        return 0;
    }

    intl index = n - k;
    intl cnt = 0;
    for(intl i = 0; i < index; i++){
        int cl = k + i;
        
        if(a[k] == a[cl + 1]){
            cnt++;
        }
    }

    cout << k + cnt;

    return 0;
}