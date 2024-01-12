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

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

int sz[MAX], par[MAX], bank[MAX];
pair<int, int> maxi[MAX]; 
vector<int> adj[MAX];
set<int, greater<int>> s;
int n, m; 

int Find_par(int v) { return (par[v] == v ? v : par[v] = Find_par(par[v])); }

void merge(int A, int B){
    A = Find_par(A); B = Find_par(B);
    if(A == B) return;

    if(sz[A] > sz[B]) swap(A, B);
    vector<int> mx; 
    s.erase(maxi[A].F); s.erase(maxi[A].S);
    s.erase(maxi[B].F); s.erase(maxi[B].S);

    mx.pb(maxi[A].F); mx.pb(maxi[A].S);
    mx.pb(maxi[B].F); mx.pb(maxi[B].S);

    sort(mx.rbegin(), mx.rend());

    sz[B] += sz[A];
    par[A] = B;
    maxi[B] = {mx[0], mx[1]};
    s.insert(mx[0]); s.insert(mx[1]);
}

void clear(){
    s.clear();
    for(int i = 1; i <= n; i++) adj[i].clear();
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        clear();
        for(int i = 1; i < n; i++){
            int x, y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1, maxi[i] = {i, -1};

        vector<pair<int, int>> ord;
        for(int i = 1; i <= m; i++){
            int t, c; cin >> t >> c;
            ord.pb({t, c});
            if(t == 1) bank[c] = 1;
        }

        reverse(all(ord));

        for(int i = 1; i <= n; i++) if(!bank[i]){
            // cout << i << endl;
            for(int u: adj[i]) if(!bank[u]){
                merge(i, u);
            }
        }

        for(int i = 1; i <= n; i++) if(par[i] == i) s.insert(i);

        vector<int> ans;
        for(auto [t, c]: ord){
            if(t == 1){
                bank[c] = 0; s.erase(c);
                for(int u: adj[c]) if(!bank[u])
                    merge(c, u);
            }
            else{
                // cout << endl;
                int cnt = 0, res = -1;
                c = Find_par(c);
                for(int u: s){
                    int x = Find_par(u);
                    // cout << u << " ";
                    if(x == c) continue;
                    cnt++;

                    if(cnt == 2) {res = u; break;}
                }


                ans.pb(res);
                // cout << "\nAns: " << res << endl;
                // cout << "\n-------------\n";
            }
        }

        reverse(all(ans));
        for(int u: ans) cout << u << endl;
        // cout << endl;
    }

}