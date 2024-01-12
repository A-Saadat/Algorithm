#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err_dp(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int MOD = 1e9 + 7; 

int dp[2][MAX]; 
vector<char> v, tt;
vector<int> tp; // ? tp = turning point

string str, fin;
int n, k, kp;

inline void find_turning_point(){ // ? turning point is an index which can turn the "START" string to the "END" string in one move
    for(auto u: fin) v.pb(u);
    for(int i = 0; i < n; i++){ // ? 1 -> n - 1
        tt.clear();
        for(int j = i + 1; j < n; j++) tt.pb(str[j]); // ? i + 1 -> n
        for(int j = 0; j <= i; j++) tt.pb(str[j]); // ? 1 -> i
        
        if(tt == v) tp.pb(i); // ! Remember that index of turning points are 0-base
    }
}

inline void Update_dp(){
    ll sum = 0, ns = 0;
    for(int m = 0; m < n - 1; m++) dp[1][m] = 1, sum += dp[1][m]; // ? base of dp
    // for(int m = 0; m <= n - 1; m++) err_dp(1, m)

    // cout << "\n-----------------\n";
    int h = 2;
    while(--k){
        // cout << "sum = " << sum << endl;
        for(int m = 0; m < n; m++){
            dp[h][m] = (sum - dp[3 - h][m]) % MOD;
            // cout << "dp[" << h << "][" << m << "] = " << dp[h][m] << " won't update from dp[" << 3 - h << "][" << m << "] = " << dp[3 - h][m] << endl;
            ns += dp[h][m];
            ns %= MOD;
        } 
        sum = ns;
        ns = 0;
        h = 3 - h;


        // cout << "\n----------------\n";
    }
}

inline ll Solve(){
    find_turning_point();
    Update_dp();

    ll ans = 0;
    for(int u: tp) ans += dp[(!(kp % 2) ? 2 : 1)][u] % MOD;

    return ans % MOD;
}

main()
{IOS;

    cin >> str; cin >> fin; cin >> k; kp = k;
    n = str.size();

    if(k == 0){
        if(str == fin) cout << 1;
        else cout << 0;

        return 0;
    }

    cout << Solve();
}