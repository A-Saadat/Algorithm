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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector<int> v; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        v.clear(); v.pb(INF);
        int n; cin >> n;
        
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.pb(x);
        }
        v.pb(INF);

        v.erase(unique(all(v)), v.end());
        n = v.size();
        int val = 0;
        for(int i = 1; i < n; i++)
            if(v[i - 1] > v[i] && v[i] < v[i + 1])
                val++;

        cout << (val == 1 ? "YES\n" : "NO\n");
    }

}