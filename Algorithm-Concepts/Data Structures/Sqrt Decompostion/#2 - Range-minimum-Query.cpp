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
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX], dp[MAX]; 
int sq, mini = INF, n;

inline void _set(int l, int val){
    mini = INF; a[l] = val;
    int k = l / sq;
    l = max(l - (l % sq), 1);
    int r = min( ( (l - (l % sq)) + sq - 1 ), n );

    for(int i = l; i <= r; i++) mini = min(mini, a[i]);

    dp[k] = mini;
}

inline int _get(int l, int r){
    mini = INF;
    for(int i = l; i <= r;){
        if(i % sq == 0 && i + sq - 1 <= r) {
            mini = min( mini, dp[i / sq] );
            i += sq;
        }
        else{
            mini = min( mini, a[i]);
            i++;
        }
    }

    return mini;
}

main()
{IOS;

    cin >> n;
    sq = sqrt(n + .0);

    fill(dp, dp + MAX, INF);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i / sq] = min( dp[i / sq], a[i] );
    }

    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, val; cin >> l >> val;
            _set(l, val);
        }
        else{
            int l, r; cin >> l >> r;
            cout << _get(l, r) << endl;
        }
    }
}