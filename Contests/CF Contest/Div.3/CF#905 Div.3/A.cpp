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
        vector<int> num; 
        num.pb(1);
        for(int i = 1; i <= 4; i++){
            char c; cin >> c;
            if(c == '0') num.pb(10);
            else num.pb(c - '0');
        }

        int ans = 4;
        for(int i = 1; i <= 4; i++){
            ans += abs(num[i] - num[i - 1]);
        }
        cout << ans << endl;
    }
}