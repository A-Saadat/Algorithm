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

int st[MAX], fn[MAX], w[MAX];
int dis[MAX];
int n, m, s; 
bool isOk;

void relax(int e){
    int v = st[e], u = fn[e];
    if(dis[u] > dis[v] + w[e]) dis[u] = dis[v] + w[e], isOk = 1;
}

void Bellman_ford(){
    for(int i = 1; i < n; i++)
        for(int j = 1; j <= m; j++)
            relax(j);

    isOk = 0;
    for(int i = 1; i <= m; i++) relax(i);
}

main()
{IOS;

    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++){
        int v, u, wg; cin >> v >> u >> wg;
        st[i] = v;
        fn[i] = u;
        w[i] = wg;
    }    

    for(int i = 1; i <= n; i++) if(i != s) dis[i] = INF;
    Bellman_ford();
}