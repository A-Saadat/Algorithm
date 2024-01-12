#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err_par(i) cout << "par[" << i << "] = " << par[i] << endl;
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e3 + 100; 
const int INF = 1e9 + 7; 

set<int> ky[MAX];
set<string> rsd[MAX]; 
map< pair<int, int>, int > edg;
int col[MAX];

int n, m, k;

inline void merge(int A, int B){
    if(ky[A].size() > ky[B].size()) 
        swap(A, B);

    fort(itr, ky[A]){
        col[ *itr ] = B;
        ky[B].insert( *itr );
    }

    fort(itr, rsd[A])
        rsd[B].insert( *itr );

    ky[A].clear();
    rsd[A].clear();
}

inline void Solve(int A, int B){
    if(col[A] == col[B]) return;

    int edg_id = edg[ {A, B} ];
    bool c1 = ky[ col[A] ].find(edg_id) != ky[A].end();
    bool c2 = ky[ col[B] ].find(edg_id) != ky[B].end();

    if(c1 || c2)
        merge(col[A], col[B]);
}

main()
{IOS;


    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) col[i] = i;

    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        edg[ {x, y} ] = i;
        edg[ {y, x} ] = i;
    }

    for(int i = 1; i <= k; i++){
        string s; cin >> s;
        int room; cin >> room;
        rsd[room].insert(s);
        int kNumber; cin >> kNumber;
        for(int i = 1; i <= kNumber; i++){
            int x; cin >> x;
            ky[room].insert(x);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << i << ":\n";
        fort(itr, ky[i]) cout << *itr << ' ';
        cout << endl;
        fort(itr, rsd[i]) cout << *itr << ' ';
        cout << "\n-------------------\n";
    }

    cout << "\n-------------------------- *************** ---------------------------------- \n";

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            Solve(i, j);


    for(int i = 1; i <= n; i++){
        cout << i << ":\n";
        fort(itr, ky[i]) cout << *itr << ' ';
        cout << endl;
        fort(itr, rsd[i]) cout << *itr << ' ';
        cout << "\n-------------------\n";
    }
    
}