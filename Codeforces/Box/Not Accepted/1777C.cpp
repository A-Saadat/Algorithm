#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define uni(v) v.erase(unique(all(v)), v.end()) 
#define int long long 

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

vector<int> factors[MAX];
int mul[MAX], a[MAX];
int cnt, n, m; 

inline void factor_finder(){
    for(int i = 1; i <= MAX - 9; i++){
        for(int j = i; j <= MAX - 9; j+=i){
            factors[j].pb(i);
        }
        uni(factors[i]);
    }
}

inline void _add(int x){
    for(int u: factors[x]){
        if(u > m) break;

        if(!mul[u]++) cnt++;
    }
}

inline void _remove(int x){
    for(int u: factors[x]){
        if(u > m) break;

        if(--mul[u] == 0) cnt--;
    }
}

main()
{IOS;

    factor_finder();
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= m + 2; i++) mul[i] = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);

        int r = 0;
        int ans = INF;
        for(int l = 1; l <= n; l++){ // ? two pointer
            while(cnt < m && r <= n){
                r++;
                _add(a[r]);
            }
            if(cnt == m)
                ans = min(ans, a[r] - a[l]);

            _remove(a[l]);
        }

        cout << (ans < INF ? ans : -1) << endl;
    }

}