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
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX], comp[MAX];
int col[MAX]; 

inline bool Lucky(int x){
    while(x > 0){
        if((x % 10 != 4) && (x % 10 != 7)) return 0;
        x /= 10;
    }

    return 1;
}

inline void merge(int A, int B){
    if(A == B) return;

    if(comp[A].size() > comp[B].size()) swap(A, B);

    for(int u: comp[A]){
        col[u] = B;
        comp[B].pb(u);
    }
    comp[A].clear();
}

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        comp[i].pb(i);
        col[i] = i;
    }

    for(int i = 1; i < n; i++){
        int x, y, val; cin >> x >> y >> val;
        if(!Lucky(val)) merge(col[x], col[y]);
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans += 1LL * (comp[i].size()) * (n - comp[i].size()) * (n - comp[i].size() - 1);

    cout << ans << endl;

}