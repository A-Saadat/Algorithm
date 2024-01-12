#include <bits/stdc++.h> // ! orj
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
typedef vector<int> vi;

const int MAX = 2e3 + 10; 
const int INF = 1e9 + 7; 

vector< pair<int, int> > np;
vector< pair<int, pair<int, int> > > edg;
vector<int> p;
int c[MAX], k[MAX], par[MAX], sz[MAX], x[MAX], y[MAX];

int MST, n;

int Find_par(int v){
    if(par[v] == v) return v;
    return par[v] = Find_par( par[v] );
}

inline void merge(int A, int B){
    A = Find_par(A);
    B = Find_par(B);

    if(sz[A] > sz[B]) swap(A, B);

    par[A] = B;
    sz[B] += sz[A];
}

inline void Draw_Graph(){
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++){
            int w = (k[i] + k[j]) * ( abs( x[i] - x[j] ) + abs( y[i] - y[j] ) );
            edg.pb( {w, {i, j}} );
        }
}

inline void Find_MST(){
    for(auto x: edg){
        int w = x.F, v = x.S.F, u = x.S.S;

        if(Find_par(v) == Find_par(u)) continue;

        merge(v, u);
        MST += w;
        if(v == 0) p.pb(u);
        else np.pb( {v, u} );
    }
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        par[i] = i;
        sz[i] = 1;
    } 

    sz[0] = 1;

    int mini = INF, id = 0;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        edg.pb( {c[i], {0, i}} );
    } 
    for(int i = 1; i <= n; i++) cin >> k[i];

    Draw_Graph();
    sort(all(edg));
    Find_MST();

    cout << MST << endl;
    cout << p.size() << endl;
    for(int u: p) cout << u << ' ';
    cout << endl << np.size() << endl;
    for(auto u: np) cout << u.F << ' ' << u.S << endl;

}