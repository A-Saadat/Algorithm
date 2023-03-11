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

const ll MaxN = 2000 + 10; 
const ll INF = 1e9 + 7; 

int hig[MaxN][MaxN], mark[MaxN][MaxN]; 
queue< pair<int, int> > q;

int n, m, maxHig;

int G[] = {+1, -1, 0, 0};
int H[] = {0, 0, -1, +1};

void bfs(){
    while(!q.empty()){
        auto h = q.front(); mark[h.F][h.S] = 1;

        forn(i, 0, 4){
            int mx = h.F + G[i], my = h.S + H[i];
            if(mark[mx][my] || mx > n || my > m || mx <= 0 || my <= 0) continue;

            q.push( {mx, my} );
            hig[mx][my] = hig[h.F][h.S] + 1, maxHig = max(maxHig, hig[mx][my]);
            mark[mx][my] = 1;
        }

        q.pop();
    }
}

main()
{IOS;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    cin >> n >> m;
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        q.push( {x, y} );
        hig[x][y] = 0;
        mark[x][y] = 1;
    }

    bfs();

    bool isOk = false;
    forn(i,1,n + 1)
        forn(j,1, m + 1)
            if(hig[i][j] == maxHig && !isOk) cout << i << ' ' << j << endl, isOk = true;
    
}