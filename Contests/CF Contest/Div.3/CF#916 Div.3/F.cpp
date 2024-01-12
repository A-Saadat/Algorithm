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

vector<int> adj[MAX]; 
int cnt[MAX], hig[MAX];

void dfs(int v){
    for(int u: adj[v]){
        hig[u] = hig[v] + 1;
        cnt[hig[u]]++;
        dfs(u);
    }
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 2; i <= n; i++){
            int p; cin >> p;
            adj[p].pb(i);
        }

        hig[1] = 1;
        dfs(1);

        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += cnt[i] / 2;
        }

        cout << "Ans: " << ans << endl;
    }

}