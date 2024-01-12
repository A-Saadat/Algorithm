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
typedef vector<int> vi;

const int MAX = 1e6 + 100; 
const int INF = 1e9 + 7; 

int dp[MAX], a[MAX]; 

main()
{IOS;

    int n, x; cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= MAX - 10; i++) dp[i] = INF;

    for(int i = 1; i <= x; i++) {
        int mini = INF;
        for(int j = 1; j <= n; j++){
            if(a[j] > i) continue;

            mini = min( mini, dp[i - a[j]] );
        }

        dp[i] = mini + 1;
    }

    cout << (dp[x] < INF ? dp[x] : -1);
}