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

int a[MAX], b[MAX], ans[MAX], ps[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        

        for(int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
        sort(b + 1, b + n + 1);
        for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + b[i];
        for(int i = 1; i <= n; i++) ans[i] = -1;

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            while(i < n && ps[i] >= b[i + 1]) cnt++, i++;
            ans[i] = cnt;
            cnt++;
        }

        for(int i = n - 1; i >= 2; i--) {
            if(ans[i] == -1) ans[i] = ans[i + 1];
        }

        map<int, int> mp;
        for(int i = 1; i <= n; i++) mp[b[i]] = ans[i];

        for(int i = 1; i <= n; i++) cout << mp[a[i]] << ' ';
        cout << endl;

    }

}