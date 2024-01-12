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

const int MAX = 1e6 + 10; 
const int INF = 1e9 + 7; 

int c[MAX]; 
pair<int, int> mon[MAX];

int f(int x, int y){
    return ((x / y) + ((x % y) > 0));
}

inline void Solve(){
    int A, B, n; cin >> A >> B >> n;
    for(int i = 1; i <= n; i++) cin >> mon[i].F;
    for(int i = 1; i <= n; i++) cin >> mon[i].S;

    sort(mon + 1, mon + n + 1);
    
    for(int i = 1; i <= n; i++){
        c[i] = f(mon[i].S, A);
    }

    bool isOk = 1;
    for(int i = 1; i < n; i++){
        int res = 1LL * c[i] * mon[i].F;
        B -= res;
    } 

    int res = 1LL * (c[n] - 1) * mon[n].F;
    B -= res;
    if(B <= 0) isOk = 0; 

    cout << (isOk ? "YES\n" : "NO\n");
}

main()
{IOS;

    int t; cin >> t;
    while(t--){

        Solve();
    
    }
}