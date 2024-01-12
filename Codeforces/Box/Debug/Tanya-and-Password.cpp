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

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

struct nod{int u; int id; char c;};

map<string, int> mp;
map<int, string> mp2;

vector<nod> adj[MAX];
bool mark[MAX];
int pnt[(MAX << 2)], in[(MAX << 2)], out[(MAX << 2)];
int self_loop[(MAX << 2)];

string s, fr, sc, ans;

void dfs(int v){
    for(int i = pnt[v]; i < adj[v].size(); i++){
        int u = adj[v][i].u, id = adj[v][i].id; char c = adj[v][i].c;
        
        pnt[v]++;
        if(mark[id]) continue;
        mark[id] = 1;

        dfs(u);
        ans += c;
    }
}

main()
{IOS;

    int n; cin >> n;
    int idx = 0;

    vector<string> ss;
    for(int i = 1; i <= n; i++){
        cin >> s; ss.pb(s);
        fr = s.substr(0, 2);
        sc = s.substr(1, 3);

        if(!mp[fr]) mp[fr] = ++idx, mp2[idx] = fr;
        if(!mp[sc]) mp[sc] = ++idx, mp2[idx] = sc;

        adj[mp[fr]].pb({mp[sc], i, s.back()});
        in[mp[sc]]++;
        out[mp[fr]]++;

        if(fr == sc) self_loop[mp[fr]]++;
    }

    int str = 0;
    for(int i = 1; i <= idx; i++)
        if(out[i] - in[i] == 1) str = i;


    if(n == 2 && (ss[0] == ss[1])) {cout << "NO\n"; return 0;} 
    if(idx == 1){
        cout << "YES\n";
        for(int i = 1; i <= n + 2; i++) cout << ss[0][0];
        return 0;
    }

    dfs((str == 0 ? 1 : str));

    bool isOk = 1;
    for(int i = 1; i <= n; i++){
        if(!mark[i]) isOk = 0;
    }

    for(int i = 1; i <= idx; i++){
        if(self_loop[i] > 1) isOk = 0;
    }

    if(isOk){
        cout << "YES\n";
        s = mp2[(str == 0 ? 1 : str)];
        reverse(all(s));
        ans += s;

        reverse(all(ans));
        cout << ans << endl;
    }
    else{
        cout << "NO\n";
    }
    
}