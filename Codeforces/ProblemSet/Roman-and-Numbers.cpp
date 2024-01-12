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

const int MAX = 18 + 10;
const int M = (1 << 18) + 10;
const int INF = 1e9 + 7; 

int a[MAX], cnt[MAX];
int dp[M][110], fact[MAX]; 
int n, m;

string bin(int mask){
    string ans;
    while(mask > 0){
        if(mask & 1) ans += '1';
        else ans += '0';
        mask >>= 1;
    }

    while(ans.size() < n) ans += '0';
    return ans;
}

main()
{IOS;

    string s; cin >> s; n = s.size(), m; cin >> m; 
    for(int i = 0; i < n; i++){
        a[i] = s[i] - '0';
        cnt[a[i]]++;
    } 

    fact[1] = 1;
    for(int i = 2; i <= 18; i++) fact[i] = 1LL * fact[i - 1] * i;

    for(int i = 0; i < n; i++) {
        if(a[i] == 0) continue; 
        dp[(1 << i)][a[i] % m] = 1; 
    }

    for(int mask = 1; mask < (1 << n); mask++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                if(!((mask >> k) & 1)) 
                    dp[(mask | (1 << k))][((j * 10 + a[k]) % m)] += dp[mask][j];


    int ans = dp[(1 << n) - 1][0];
    for(int i = 0; i < 10; i++)
        if(cnt[i] > 1) ans = ans / fact[cnt[i]];
        
    cout << ans << endl;
}