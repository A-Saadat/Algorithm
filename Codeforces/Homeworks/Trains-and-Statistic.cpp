// ! THIS IS MY 8-TH TRY FOR THIS PROBLEM, WISH ME LUCK

#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define int long long 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err_mx(i, j) cout << "mx[" << i << "][" << i + (1 << j) << "] = " << mx[i][j].F << " with index " << mx[i][j].S << endl;
typedef vector<int> vi;

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

pair<int, int> mx[MAX][30]; // ? mx[i][j] = the Maximum element in [i, i + 2^j]
int a[MAX], dp[MAX]; 
int n; 
int sum = 1;

inline void Update_mx(){
    for(int i = 1; i <= n - 2; i++) 
        mx[i][0] = max( make_pair(a[i], i), make_pair(a[i + 1], i + 1) );

    for(int k = 1; k <= 22; k++)
        for(int i = 1; i + (1 << k) <= n - 1; i++)
            mx[i][k] = max( mx[i][k - 1], mx[i + (1 << (k - 1))][k - 1] );
}

inline int Find_max(int L, int R) {
    if(L == R) return L;

    int lg = log2(R - L);
    return max( mx[L][lg], mx[ R - (1 << lg) ][lg] ).S;
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i < n; i++) cin >> a[i];
    Update_mx();
    dp[n] = 0, dp[n - 1] = 1;
    for(int i = n - 2; i >= 1; i--){
        int m = Find_max(i + 1, min(n - 1, a[i]));
        dp[i] = dp[m] - (a[i] - m) + n - i;
        sum += dp[i];
    }

    cout << sum;
}