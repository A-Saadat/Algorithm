#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define all(v) v.begin(), v.end()
#define int long long 
#define pb push_back
#define elif else if 
#define S second 
#define F first 

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

string s[MAX];

struct Trie{
    map<pair<int, char>, int> mp;
    vector<pair<int, char>> adj[MAX];
    int cnt = 1;

    void dfs(int i, int v, int pnt){
        if(pnt == s[i].size()) return;

        if(!mp[{v, s[i][pnt]}]){
            mp[{v, s[i][pnt]}] = cnt + 1;
            adj[v].pb({cnt + 1, s[i][pnt]});
            ++cnt;
        } 

        dfs(i, mp[{v, s[i][pnt]}], pnt + 1);
    }
} t;


signed main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];

    for(int i = 1; i <= n; i++) t.dfs(i, 1, 0);

    for(int i = 1; i <= t.cnt; i++){
        cout << i << ": ";
        for(auto [u, c]: t.adj[i]) cout << "{" << u << ", " << c << "} | ";
        cout << "\n--------------------\n";
    }

}