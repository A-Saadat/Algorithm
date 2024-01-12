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

const int MAX = 5e5 + 10; 
const int INF = 1e9 + 7; 
const int sq = 317;

int a[MAX]; 
vector<int> v[MAX];

inline int _get(int l, int r, int val){
    int ans = 0;
    for(int i = l; i <= r;){
        if(i % sq == 0 && i + sq <= r){
            ans += v[i / sq].end() - lower_bound(all(v[i / sq]), val);
            i += sq;
        }
        else{
            ans += (a[i] >= val);
            i++;
        }
    }

    return ans;
}

inline void _set(int l, int val){
    int bl = l / sq;
    for(int i = 0; i < v[bl].size(); i++){
        if(v[bl][i] == a[l]){
            v[bl][i] = val;
            break;
        }
    }

    sort(all(v[bl]));
    a[l] = val;
}

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v[i / sq].pb(a[i]);
    } 

    for(int i = 0; i <= n; i++) sort( all(v[i]) );
    
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 0){
            int l, r, val; cin >> l >> r >> val;
            cout << _get(l, r, val) << endl;
        }
        else{
            int l, val; cin >> l >> val;
            _set(l, val);
        }
    }

}