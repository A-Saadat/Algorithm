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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int add[MAX];
int n, q; 

struct Fenwick{
    void set(int id, int val){
        while(id > 0){
            add[id] += val;
            id ^= (id & -id);
        }
    }

    int get(int id){
        int ans = 0;
        while(id <= n){
            ans += add[id];
            id += (id & -id);
        }
        return ans;
    }
} fen;

main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        fen.set(i, x);
        fen.set(i - 1, -x);
    }    

    cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r, val; cin >> l >> r >> val;
            fen.set(r, val);
            fen.set(l - 1, -val);
        }
        else{
            int idx; cin >> idx;
            cout << fen.get(idx) << endl;
        }
    }

}