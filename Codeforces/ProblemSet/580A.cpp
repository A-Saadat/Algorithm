#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100000

int main (void)
{
    intl n;
    cin >> n;

    intl a[def];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    intl cnt = 1, ans = 0;
    
    if(n != 1){
        for(int i = 1; i < n; i++){
            if(a[i] >= a[i - 1])
                cnt++;
            else
                cnt = 1;

            if(cnt > ans)
                ans = cnt;
        }
    }
    else{
        cout << "1";
        return 0;
    }

    cout << ans;
}