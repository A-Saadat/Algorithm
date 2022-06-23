#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100

int main (void)
{
    intl n;
    cin >> n;

    intl a[def];
    for(intl i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            cout << "HARD";
            return 0;
        }
    }

    cout << "EASY";
}