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
#define int unsigned long long 

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX]; 
vector<int> ans;

main()
{IOS;

    int t; cin >> t; 
    while(t--){
        ans.clear();
        int n; cin >> n;
        ans.pb(1);
        for(int i = 0; i < n; i++) ans.pb(pow(2, i));
        for(int u: ans) cout << u << " ";
        cout << endl;
    }
}