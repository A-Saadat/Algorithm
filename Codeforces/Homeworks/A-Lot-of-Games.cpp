#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define all(v) v.begin(), v.end() 
#define pb push_back 
#define elif else if 
#define S second 
#define F first 
#define int long long 

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

int w[MAX], l[MAX]; 
string s[MAX];
vector<int> adj[MAX];
int cnt = 1;

map<pair<int, char>, int> mp;
void build(int i, int v, int pnt){
    if(pnt == s[i].size()) return;

    if(!mp[{v, s[i][pnt]}]){
        mp[{v, s[i][pnt]}] = cnt + 1;
        adj[v].pb(cnt + 1);
        adj[cnt + 1].pb(v);
        ++cnt;
    }
    int u = mp[{v, s[i][pnt]}];
    build(i, u, pnt + 1);
}

void dfs(int v, int p){
    for(int u: adj[v]){
        if(u == p) continue;
        dfs(u, v);
    }
    
    if(adj[v].size() == 1 && v != 1) w[v] = 0, l[v] = 1;
    else{
        for(int u: adj[v]){
            if(u == p) continue;
            w[v] |= !w[u];
            l[v] |= !l[u];
        }
    }
}

signed main()
{IOS;

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= n; i++) build(i, 1, 0);

    dfs(1, 0);
    
    if(w[1] == 1 && k % 2 || w[1] == 1 && l[1] == 1) cout << "First\n";
    else cout << "Second\n"; 
}