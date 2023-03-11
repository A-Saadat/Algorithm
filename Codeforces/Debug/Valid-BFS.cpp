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

const ll MaxN = 2e5 + 10; 
const ll INF = 1e9 + 7; 

vector<int> adj[MaxN], flr[MaxN]; // ? flr = floors in BFS result tree  
int a[MaxN], mark[MaxN];
int dep[MaxN], sz[MaxN];
map<int, int> m[MaxN];

void bfs(){
    queue<int> q;
    q.push(1);  
    dep[1] = 1; flr[1].pb(1);

    while(!q.empty()){
        int h = q.front(); mark[h] = 1;
        
        for(int u: adj[h]){
            if(mark[u]) continue;
            dep[u] = dep[h] + 1;
            flr[ dep[u] ].pb(u);
            q.push(u);
        }

        q.pop();
    }
}

main()
{IOS;

    int n; cin >> n;
    forn(i,1,n){
        int x, y; cin >> x >> y;

        m[x][y] = 1;
        m[y][x] = 1;
    }

    forn(i,1,n + 1){
        cin >> a[i];
        // sz[ a[i] ] = adj[ a[i] ].size();
    } 

    // if(n == 1) { cout << "Yes" << endl; return 0; }

    // int L = 1, R = 2; // ** Set-up Two Pointer 
    // while(L < n){
    //     cout << a[L] << " -> ";
    //     while(m[ a[L] ][ a[R] ]){
    //         cout << a[R] << " -> ";
    //         cout << "*R: " <<  R << endl;
    //         R++;
    //     } 
    //     cout << endl;
    //     L++;
    // }

    // cout << "* " << L << "  " << R << endl;

    int i, j;
    for (i = 1, j = 2 ; i <= n ; i++){
        cout << a[i] << " -> ";
        while (m[a[i]][a[j]]){
            cout << a[j] << " -> ";
            j++;
        }
        cout << "\n---------\n";
    }

    if(j == n) cout << "Yes" << endl;   
    else cout << "No" << endl;
}