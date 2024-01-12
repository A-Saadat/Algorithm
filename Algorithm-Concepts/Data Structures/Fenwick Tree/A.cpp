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

int sum[MAX], a[MAX];
int n, q;

struct Fenwick{
    int get(int id){
        int ans = 0;
        while(id > 0){
            ans += sum[id];
            id ^= (id & -id);
        }
        return ans;
    }
    void set(int id, int delta){
        while(id <= n){
            sum[id] += delta;
            id += (id & -id);
        }
    }
} fen;

main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        fen.set(i, a[i]);
    }

    cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 2){
            int l, r; cin >> l >> r;
            cout << fen.get(r) - fen.get(l - 1) << endl;
        }
        else{
            int idx, val; cin >> idx >> val;
            fen.set(idx, val - a[idx]);
            a[idx] = val;
        }
    }

}
    
/*
4
5 7 2 1
*/