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

const int MAX = 1e3 + 10; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX];
int sub[MAX];
int n, x, cnt;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n >> x;

        for(int i = 1; i < n; i++){
            int x, y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        if(adj[x].size() == 1){
            cout << "Ayush\n";
            continue;
        } 

        if((n - 1) % 2) cout << "Ayush\n";
        else cout << "Ashish\n";
    }
}