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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX];
vector<int> v;
int ans;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n; v.clear();
        for(int i = 1; i <= n; i++) cin >> a[i], v.pb(a[i]);
        v.resize(distance(v.begin(), unique(all(v))));
        if(v.size() == 1){
            cout << 1 << endl;
            continue;
        }
        ans = v.size();
        for(int i = 0; i < v.size() - 2; i++){
            ans -= (v[i] < v[i + 1] && v[i + 1] < v[i + 2]);
            ans -= (v[i] > v[i + 1] && v[i + 1] > v[i + 2]);
        }
        cout << ans << endl;
    }

}