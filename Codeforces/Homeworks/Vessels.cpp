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

int rem[MAX], full[MAX], par[MAX]; 

int Find_par(int u){
    if(par[u] == u) return u;

    return par[u] = Find_par( par[u] );
}

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> full[i];
        rem[i] = full[i];
        par[i] = i;
    }   

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int u, val; cin >> u >> val;
            while(val > 0){
                u = Find_par(u);
                if(rem[u] > val){
                    rem[u] -= val;
                    val = 0;
                } 
                else{
                    val -= rem[u];
                    rem[u] = 0;
                    if(u + 1 > n) break;

                    par[u] = u + 1;
                }
            }
        }
        elif(t == 2){
            int u; cin >> u;
            cout << full[u] - rem[u] << endl;
        }
    }

}

