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

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

set<int> s;
int par[MAX], sz[MAX];
int type, u, v; 

int Find_par(int v){
    if(par[v] == v) return v;

    return par[v] = Find_par( par[v] );
}

inline void merge(int A, int B){
    A = Find_par(A);
    B = Find_par(B);

    if(A == B) return;

    if(sz[A] > sz[B]) swap(A, B);

    sz[B] += sz[A];
    par[A] = B;
}

inline void Union(int A, int B){
    auto itr = s.lower_bound(A);
        
    while(*itr < B){
        merge(*itr, B);
        s.erase(itr);
        itr = s.lower_bound(A);
    }
}

main()
{IOS;

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        s.insert(i);
        par[i] = i;
        sz[i] = 1;
    }

    while(q--){
        cin >> type >> u >> v;
        if(type == 1) merge(u, v);
        elif(type == 2) Union(u, v);
        else{
            if(Find_par(u) == Find_par(v)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
}