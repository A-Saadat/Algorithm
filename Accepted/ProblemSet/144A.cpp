#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void)
{
    intl n; 
    cin >> n;

    intl a[n + 10];
    intl mini = 0, maxi = 0, maxIdx = 0, minIdx = 0;
    for(intl i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] > maxi){
            maxi = a[i];
            maxIdx = i;
        }

        if(mini == 0){
            mini = a[i];
            minIdx = i;
        }
        else if(a[i] <= mini){
            mini = a[i];
            minIdx = i;
        }
    }

    if(maxIdx > minIdx)
        cout << (maxIdx - 1) + (n - minIdx) - 1 << endl;
    else
        cout << (maxIdx - 1) + (n - minIdx) << endl;
}