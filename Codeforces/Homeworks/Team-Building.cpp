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

const int MAX = 1e5 + 10; 
const int M = (1 << 8) + 10; 
const int INF = 1e9 + 7; 

vector< pair<int, int> > a;
int s[MAX][10], dp[MAX][M]; 
int n, p, k; 

string bin(int x){
    string ans;
    while(x > 0){
        if(x % 2) ans += '1';
        else ans += '0';
        x >>= 1;
    }
    while(ans.size() < p) ans += '0';
    reverse(all(ans));
    return ans;
}

main()
{IOS;

    cin >> n >> p >> k;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.pb( {x, i} );
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++) cin >> s[i][j];

    sort(a.rbegin(), a.rend());
    for(int i = 0; i < n; i++)
        for(int mask = 0; mask < (1 << p); mask++)
            dp[i][mask] = -1e10;
    
    for(int i = 0; i < p; i++) dp[0][(1 << i)] = s[a[0].S][i];
    dp[0][0] = a[0].F;
    
    for(int i = 1; i < n; i++){
        int val = a[i].F, id = a[i].S;
        for(int mask = 0; mask < (1 << p); mask++){
            dp[i][mask] = dp[i - 1][mask] + (i - __builtin_popcount(mask) < k ? val : 0);
            for(int j = 0; j < p; j++)
                if((mask >> j) & 1)
                    dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + s[id][j]);
        }
    }

    cout << dp[n - 1][(1 << p) - 1] << endl;
}
