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

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 
const int sq = 317;

int a[MAX], who[MAX], out[MAX];
int n, q; 

inline void prcs(int i){
    if(i + a[i] > n){
        who[i] = i;
        out[i] = 0;
        return;
    } 

    if( (i + a[i]) / sq > (i / sq) ) {
        out[i] = 1;
        who[i] = i + a[i];
    }
    else{
        out[i] = out[i + a[i]] + 1;
        who[i] = who[i + a[i]];
    }
}

inline pair<int, int> _get(int l){
    int sum = 0;
    while(l != who[l]){
        sum += out[l];
        l = who[l];
    }

    return {l, ++sum};
}

inline void _set(int l, int val){
    int k = l / sq; a[l] = val;
    for(int i = l; (i / sq) == k && i; i--)
        prcs(i);
}

main()
{IOS;

    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = n; i >= 1; i--) prcs(i);

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l; cin >> l;
            auto ans = _get(l);
            cout << ans.F << " " << ans.S << endl;
        }
        else{
            int l, val; cin >> l >> val;
            _set(l, val);
        }
    }

}