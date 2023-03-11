
// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define bp __builtin_popcount 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef map<ll, ll> mll; 
typedef set<int> si;  
typedef pair<ll,ll> pii; 
typedef vector<ll> vci;
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<char> vcc; 

const ll MaxN = 1e3; 
const ll INF = 1e9 + 7; 

vector<int> adj[MaxN], ans, leavs, tmp, mAns;
int par[MaxN], disc[MaxN], str[MaxN], ed[MaxN];
bool subTree[MaxN][MaxN];

int t;
void dfs(int v, int p){
    ++t; disc[t] = v; str[v] = t;
    par[v] = p; 
    for(int u: adj[v]){
        if(u != p) dfs(u, v);
    }

    ed[v] = t;
}

void Add_Path(int curr, int tl){
    tmp.clear();
    int c = tl;
    while(c != curr){
        tmp.pb(c);
        c = par[c];
    }
    tmp.pb(curr);
    reverse( all(tmp) );

    for(int u: tmp) ans.pb(u);
}

main()
{IOS;

    int n; cin >> n;
    forn(i,1,n){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    int leaf = 0;
    forn(i,1,n + 1)
        if(adj[i].size() == 1 && i > 1) leaf++;

    dfs(1, 1); // ? Fill the Par Array

    while(leaf--){
        int x; cin >> x;
        leavs.pb(x);
    } 

    // ** A path From vertix 1 to First Leaf
    ll curr = leavs.front();

    Add_Path(1, curr);

    forn(i,1,n + 1) // ? if the vertix u, is in the Sub Tree of i, then the subTree[i][j] = 1
        for(int j = str[i]; j <= ed[i]; j++){
            int u = disc[j];
            subTree[i][u] = 1;
        }

    leavs.pb(1); // ? At the end, we have to visit 1 again
    forn(i,0, leavs.size() - 1){
        int curr = leavs[i];
        int tl = leavs[i + 1]; // ? Target Leaf

        while(curr != 0){ // ? goes up until it visits the vertix 1
            if(subTree[curr][ leavs[i + 1] ]){
                Add_Path(curr, tl); // ? if the target vertix is in the current vartix's subtree, then we have to Add the path Between them to answer
                break;
            }
            ans.pb(curr);
            curr = par[curr];
        }
    }


    for(int u: ans) {
        int h = (mAns.size() == 0 ? 0 : mAns.back()); // ? to Prevent a Tiny Bug
        if(h != u) mAns.pb(u);
    }

    if(mAns.size() > (2 * n) - 1) cout << -1 << endl;
    else 
        for(int u: mAns) cout << u << ' ';
}   