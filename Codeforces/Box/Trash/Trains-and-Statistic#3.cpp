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
#define err_mx(i, j) cout << "mx[" << i << "][" << (i + (1 << j)) << "] = " << mx[i][j].F << " with index " << mx[i][j].S << endl;
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX], dp[MAX]; 
pair<int, int> mx[30][MAX];
int n; 

ll ans;

inline void Update_mx(){
    for(int i = 1; i < n; i++){
        pair<int, int> d1 = {a[i], i};
        pair<int, int> d2 = {a[i + 1], i + 1};

        mx[0][i] = max(d1, d2);
    }

    for(int k = 1; (1 << k) <= n; k++)
        for(int i = 1; i + (1 << k) - 1 <= n; i++)
            mx[k][i] = max( mx[k - 1][i], mx[k - 1][i + (1 << (k - 1))] );
}

inline int Find_max(int L, int R){
    int lg = log2(R - L + 1);
    return max( mx[lg][L], mx[lg][R - (1 << lg) + 1] ).S;
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i < n; i++) cin >> a[i];
    Update_mx();
    
    // for(int k = 0; (1 << k) <= n; k++){
    //     for(int i = 1; i + (1 << k) - 1 <= n; i++) err_mx(i, k);
    //     cout << "\n-------------------\n";
    // }

    dp[n] = 0;
    for(int i = n - 1; i >= 1; i--){
        int m = Find_max(i + 1, a[i]);
        dp[i] = dp[m] - (a[i] - m) + n - i;
        ans += dp[i];
    }

    cout << ans << endl;

}