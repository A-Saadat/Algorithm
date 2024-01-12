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

int a[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        set<int> L, R;
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            int l; cin >> l;
            L.insert(-l);
        }
        for(int i = 1; i <= n; i++){
            int r; cin >> r;
            R.insert(r);
        }
        for(int i = 1; i <= n; i++) cin >> a[i];

        vector<int> v;
        while(!L.empty()){
            auto it = L.begin(); int sr = -1 * (*it);
            auto it2 = R.upper_bound(sr);
            v.pb(*it2 + *it);
            L.erase(it);
            R.erase(it2);
        }

        sort(all(v), greater<int>());
        sort(a + 1, a + 1 + n);

        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += v[i - 1] * a[i];
        }

        cout <<  ans << endl;
        
    }

}