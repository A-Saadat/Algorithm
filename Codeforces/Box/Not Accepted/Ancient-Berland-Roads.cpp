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

const int MAX = 5e5 + 10; 
const int INF = 1e9 + 7; 

int sz[MAX], par[MAX], ppl[MAX];
int ans, n, m, q;
int mark[MAX];

vector<int> w[MAX];
pair<int, int> edg[MAX];
set<pair<int, int>> s, rev_s;

void _remove(int v){
    // while(true){
        auto it1 = rev_s.lower_bound({v, 0});
        auto it2 = s.lower_bound({it1->S, v});
        if(it2 == s.end() || it1 == rev_s.end()) return;
        s.erase(it2);
        rev_s.erase(it1);
    // }
}

int Find_par(int v){
    if(par[v] == v) return v;
    return par[v] = Find_par(par[v]);
}

void merge(int A, int B){
    A = Find_par(A), B = Find_par(B);
    if(A == B) return;
    if(sz[A] > sz[B]) swap(A, B);
    _remove(A);
    _remove(B);
        
    sz[B] += sz[A];
    ppl[B] += ppl[A];
    par[A] = B;
    s.insert({ppl[B], B});
    rev_s.insert({B, ppl[B]});
}

main()
{IOS;

    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        int ww; cin >> ww;
        w[i].pb(ww);
        par[i] = i;
        sz[i] = 1;
    }

    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        edg[i] = {x, y};
    }

    vector<pair<int, int>> ord;
    while(q--){
        char t; cin >> t;
        if(t == 'P') {
            int v, val; cin >> v >> val;
            w[v].pb(val);
            ord.pb({1, v});
        }
        else{
            int e; cin >> e;
            ord.pb({2, e});
            mark[e] = 1;
        }
    }

    reverse(all(ord));

    for(int i = 1; i <= n; i++) ppl[i] = w[i].back();

    for(int i = 1; i <= m; i++) if(!mark[i])
        merge(edg[i].F, edg[i].S);

    for(int i = 1; i <= n; i++){
        int p = Find_par(i);
        s.insert({ppl[p], p});
        rev_s.insert({p, ppl[p]});
    }

    // for(auto  u: s) cout << "{" << u.F << ", " << u.S << "}\n";

    vector<int> ans;
    for(auto u: ord) {
        int t = u.F, x = u.S;
        // cout << t << " " << x << " -> ";
        // cout << "* " << s.rbegin()->S << endl;
        ans.pb(s.rbegin()->F);
        // for(auto u: s) cout << "{" << u.F << ", " << u.S << "} | ";
        // cout << endl;
        // cout << t << ' ' <<  x << endl;
        if(t == 1){
            // cout << 1 << " ";
            int v = Find_par(x);
            // cout << ppl[v] << endl;
            _remove(v);
            // cout << 
            // cout << 2 << " ";
            ppl[v] -= w[x].back();
            w[x].pop_back();
            ppl[v] += w[x].back();

            s.insert({ppl[v], v});
            rev_s.insert({v, ppl[v]});
            // cout << x << ": ppl[" << v << "] = " << ppl[v] << endl;
            // cout << "\n-----------------\n";
        }
        else{
            // cout << "-> " << edg[x].F << ", " << edg[x].S << endl;
            merge(edg[x].F, edg[x].S);
        }

    }

    reverse(all(ans));
    for(int u: ans) cout << u << endl;
    

    // for(int i = 1; i <= n; i++){
    //     for(int u: w[i]) cout << u << " ";
    //     cout << endl;
    // } 



}