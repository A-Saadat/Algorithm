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
typedef vector<int> vi;

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

int a[MAX]; 
int n; 
map<int, int> L, R;

inline int Find_MEX(){
    vector<int> v;
    for(int i = 1; i <= n; i++) v.pb(a[i]);
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    for(int i = 0; i < v.size(); i++)
        if(v[i] != i) return i;

    return v.size();
}

inline bool Solve(){
    for(int i = 1; i <= n; i++){
        if(!L[a[i]]) L[a[i]] = i;
        R[a[i]] = i;
    }

    int M = Find_MEX();
    if(L[M + 1]){
        int l = L[M + 1], r = R[M + 1];
        for(int i = l; i <= r; i++) a[i] = M;
        int M2 = Find_MEX();
        return M2 == M + 1;
    }

    for(int i = 1; i <= n; i++)
        if(a[i] > M || L[a[i]] != R[a[i]]) return 1;

    return 0;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n; L.clear(), R.clear();
        for(int i = 1; i <= n; i++) cin >> a[i];
        cout << (Solve() ? "Yes" : "No") << endl;
    }    

}