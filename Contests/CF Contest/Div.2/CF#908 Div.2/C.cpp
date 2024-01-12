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
map<int, int> mark;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        mark.clear();
        int n, k; cin >> n >> k;
        vector<int> v;
        for(int i = 1; i <= n; i++) {int x; cin >> x; v.pb(x);}

        reverse(all(v)); int cnt = 0; bool isOk = 0;
        for(int curr = 0; v[curr] <= n; curr = ((curr + v[curr]) % n)){
            if(mark[curr]){ isOk = 1; break;}
            mark[curr] = 1;
            cnt++;
        }

        if(isOk || cnt >= k) cout << "Yes\n";
        else cout << "No\n";
        
    }

}