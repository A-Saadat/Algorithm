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
int sq;

inline void _set(int l, int val){
    int k = l / sq;
    dp[k] -= a[l];
    a[l] = val;
    dp[k] += a[l];
}

inline int _get(int l, int r){
    int sum = 0;
    for(int i = l; i <= r;){
        if(i % sq == 0 && i + sq - 1 <= r) {
            cout << "* " << i << endl;
            sum += dp[i / sq];
            i += sq;
        }
        else{
            sum += a[i];
            i++;
        }
    }

    return sum;
}

main()
{IOS;

    int n; cin >> n;
    sq = sqrt(n + .0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i / sq] += a[i];
    }

    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, val; cin >> l >> val;
            _set(l, val);
        }
        else {
            int l, r; cin >> l >> r;
            cout << _get(l, r) << endl;
        }
    }
}