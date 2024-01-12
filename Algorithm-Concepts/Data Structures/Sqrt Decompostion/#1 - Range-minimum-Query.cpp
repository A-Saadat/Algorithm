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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX], dp[MAX]; 
int sq, mini = INF;

inline void _set(int l, int val){
    mini = INF; a[l] = val;
    int k = l / sq + 1;
    l = (k - 1) * sq;
    for(int i = l; i <= (k * sq) - 1; i++) mini = min(mini, a[i]);

    dp[k] = mini;
}

inline int _get(int l, int r){
    mini = INF;
    if(l / sq == r / sq) {
        for(int i = l; i <= r; i++) mini = min(mini, a[i]);
        return mini;
    }
    while(l % sq){
        mini = min(mini, a[l]);
        l++;
    }

    while(l / sq != r / sq){
        mini = min(mini, dp[(l / sq) + 1]);
        l += sq;
    }

    for(int i = l; i <= r; i++) mini = min(mini, a[i]);
    return mini;
}

main()
{IOS;

    int n; cin >> n;
    sq = sqrt(n + .0);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(!(i % sq)){
            dp[i / sq] = mini;
            mini = INF;
        }

        mini = min(a[i], mini);
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