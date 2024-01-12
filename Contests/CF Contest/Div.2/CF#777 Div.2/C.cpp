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

const int MAX = 100 + 10; 
const int INF = 1e9 + 7; 

int a[MAX][MAX]; 
string s[MAX];

signed main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> s[i];

        vector<pair<int, int>> w;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < m; j++){
                a[i][j + 1] = s[i][j];
                if(s[i][j] == '0') w.pb({i, j + 1});
            } 
        }

        vector<pair<pair<int, int>, pair<int, int>>> ans;
        for(int i = 1; i <= n; i++){
            for(int j = m; j > 1; j--){
                if(a[i][j] == '0') continue;
                ans.pb({{i, j - 1}, {i, j}});
            }
        }

        for(int i = n; i > 1; i--){
            if(a[i][1] == '0') continue;
            ans.pb({{i - 1, 1}, {i, 1}});
        } 

        if(a[1][1] != '0') cout << -1 << endl;
        else{
            cout << ans.size() << endl;
            for(auto u: ans){
                cout << u.F.F << " " << u.F.S << " " << u.S.F << " " << u.S.S << endl;
            }
        }

    }
    

}
