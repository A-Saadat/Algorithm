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

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

int h[MAX], p[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        vector< pair<int, int> > v;
        int n, k; cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> h[i];    
        for(int i = 1; i <= n; i++) cin >> p[i];

        for(int i = 1; i <= n; i++)
            v.pb( {p[i], h[i]} );

        sort(v.rbegin(), v.rend());
//         for(auto u: v) cout << "{" << u.F << ", " << u.S << "}\n";
// cout << "\n-------------------\n";
        for(int i = 0; i < v.size(); i++) v.back().S -= k;

        int sum = k;
        while(k > 0 && (int)v.size() > 0){
            while(v.back().S - sum <= 0){
                v.back().S -= sum;
                v.pop_back();
            } 
            cout << "{" << v.back().F << ", " << v.back().S << "}\n";
            if(v.empty()) break;
            int power = v.back().F;
            sum += k;
            k -= power;

        }

        // for(auto u: v) cout << "{" << u.F << ", " << u.S << "}\n";
        if(v.empty()) cout << "YES\n";
        else cout << "NO\n";
    }

}