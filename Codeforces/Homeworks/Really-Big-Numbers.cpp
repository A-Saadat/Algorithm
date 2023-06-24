#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++)  
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
typedef long long int ll; 

const int MaxN = 1e6; 
const int MOD = 1e9 + 7;  

main()
{IOS;

    ll n, s; cin >> n >> s;

    ll L = 0, R = n + 1;
    while(R - L > 1){
        ll mid = (R + L) / 2;

        ll a = mid, sum = 0;
        while(a >= 1){
            int x = a % 10;
            sum += x;
            a /= 10;
        }

        if(mid - sum >= s) R = mid;
        else L = mid;

    }

    cout << n - R + 1 << endl;

}