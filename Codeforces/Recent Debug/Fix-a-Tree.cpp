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
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 

int a[MaxN], mark[MaxN];
vector<int> adj[MaxN]; 
int n, root, x, y, cnt;

void dfs(int v, int par){
    mark[v] = 1;
    for(int u: adj[v]){
        if(mark[u] && par != u) { // ? it means we found ourselves in a Cycle
            x = u, y = v;
        }
        elif(!mark[u]) dfs(u, v);
    }
}

void draw_graph(){
    forn(i,1,n + 1) adj[i].clear();

    forn(i,1,n + 1){
        adj[ a[i] ].pb(i);
        adj[i].pb( a[i] );
    }
}

main()
{IOS;

    cin >> n;

    bool isRooted = false;
    forn(i,1, n + 1){
        cin >> a[i];
        if(a[i] == i && !isRooted) root = a[i], isRooted = 1;
        elif(a[i] == i && isRooted && a[i] != root) a[i] = root, cnt++; // ? Removing Loops

        else{ // ? Constructing the Graph
            adj[ a[i] ].pb(i);
            adj[i].pb( a[i] );
        }
        
    }

    if(!isRooted){ // * If the is no Root (Loop) in the Given Sequence, we Have to FIND ONE
        forn(i,1,n + 1){
            dfs(i, a[i]); // ? We want to find a edge in Cycle, then convert it to root of the tree

            if(x && y) break; // ? if we found one, we can stop
        }

        if(a[x] == y){
            a[x] = x;
            ++cnt;
            root = x;
        } 
        else{
            a[y] = y;
            ++cnt;
            root = y;
        }

        draw_graph(); // ? we Updated the Array of the graph, so we have to apply changes to the adj
    }


    forn(i,1,n + 1){
        if(mark[i]) continue;

        x = 0, y = 0;
        dfs(i, a[i]); // * to find one of the edges in the current cohesive component

        if(!x || !y) continue; // * it means there is no cycle on that cohesive component

        if(a[x] == y){
            a[x] = root;
            ++cnt;
        } 
        else{
            a[y] = root;
            ++cnt;
        } 

    }

    cout << cnt << endl;
    forn(i,1,n + 1) cout << a[i] << ' '; 
}