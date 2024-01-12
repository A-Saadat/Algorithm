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

int a[MAX], ps[MAX];
map<int, int> mp; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n; mp.clear();
        string s; cin >> s;
        for(int i = 0; i < s.size(); i++){
            int x = (int)s[i] - 48;
            a[i] = x;
        }

        for(int i = 1; i <= n; i++)
            ps[i] = ps[i - 1] + a[i - 1];

        for(int i = 0; i <= n; i++) mp[ ps[i] - i ]++;

        int ans = 0;
        fort(itr, mp) {
            int cnt = itr->S;
            ans += cnt * (cnt - 1) / 2;
        }  

        cout << ans << endl;
    }

}