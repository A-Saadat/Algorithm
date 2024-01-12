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

const int MAX = 20 + 1; 
const int M = (1 << MAX) + 1;
const int INF = 1e9 + 7; 

int a[MAX], b[MAX]; 
int ps[MAX], sum[M], dp[M];
int n, m; 

string bin(int x){
    string ans;
    while(x > 0){
        if(x % 2) ans += '1';
        else ans += '0';
        x >>= 1;
    }

    return ans;
}

inline void mask_sum(){
    int s = 0;
    for(int i = 1; i <= m; i++) s += b[i];
    sum[(1 << m) - 1] = s;
    for(int mask = (1 << m) - 2; mask >= 0; mask--){
        for(int j = m - 1; j >= 0; j--) 
            if(!((mask >> j) & 1)){
                sum[mask] = sum[mask ^ (1 << j)] -  b[j + 1];
            }
    }
}

main()
{IOS;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i], ps[i] = ps[i - 1] + a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    mask_sum();

    for(int mask = 1; mask < (1 << m); mask++){
        int maxi = 0;
        for(int j = 0; j < m; j++){
            if((mask >> j) & 1) maxi = max(maxi, dp[mask ^ (1 << j)]);
            dp[mask] = maxi + (sum[mask] == ps[maxi + 1]);
        }
    }

    if(dp[(1 << m) - 1] == n) cout << "YES\n";
    else cout << "NO\n"; 
}