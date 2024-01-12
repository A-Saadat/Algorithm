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
// #define int long long 

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

map<string, vector<int>> mp;
vector<string> v;
vector<pair<int, char>> adj[MAX];
int mark[MAX];

inline void build(int id, string s, int lim, char det){
    string tmp;
    for(int i = 0; i < lim; i++){
        tmp = s.substr(1, 3);
        char c =(char)(i + det); 
        tmp+=c;

        for(int u: mp[tmp]){
            if(u == id) continue;
            adj[id].pb({u, c});
        }
    }
}

string ans = "";
void dfs(int v){
    mark[v] = 1;
    for(auto x: adj[v]){
        int u = x.F; char c = x.S;
        if(mark[u]) continue;

        ans += c;
        dfs(u);
    }
}

main()
{IOS;

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        mp[s].pb(i);
        v.pb(s);
    }

    for(int i = 0; i < n; i++){
        build(i, v[i], 26, 'a');
        build(i, v[i], 26, 'A');
        build(i, v[i], 10, '0');
    }

    ans = v[0];
    dfs(0);

    if(ans.size() != n + 2) cout << "NO\n";
    else cout << "YES\n" << ans << endl;
}