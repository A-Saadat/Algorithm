#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define int long long 

const int MAX = 1e6; 
const int MOD = 1e9 + 7; 

inline int cu_pow(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }
    
    return ans;
}

main()
{IOS;

    int a, b; // cin >> a >> b;

    a = 3;
    b = 5;

    cout << cu_pow(a, b);

}