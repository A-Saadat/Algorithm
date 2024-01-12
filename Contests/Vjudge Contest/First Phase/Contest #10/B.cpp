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

int a[MAX], mark[MAX], cnt[MAX]; 
vector<int> divi[MAX];

main()
{IOS;

    for(int i = 1; i <= 1e5 + 1; i++) for(int j = i; j <= 1e5 + 1; j+=i) divi[j].pb(i);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> a[i]; 
        sort(a + 1, a + n + 1);
        int l = 1, r = 1, ans = INF;
        set<int> s;

        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(int u: divi[a[i]])
                if(u <= m) cnt++;

            if(cnt == m) {ans = 0; break;}
        }

        while(r <= n){
            for(int u: divi[a[r]]){
                if(u > m) continue;
                s.insert(u);
                cnt[u]++;
            }
            while(s.size() == m && l < r){
                ans = min(ans, a[r] - a[l]);
                for(int u: divi[a[l]]){
                    if(u > m) continue;
                    cnt[u]--;
                    if(!cnt[u]) s.erase(u); 
                }
                l++;
            }

            r++;
        }

        cout << (ans == INF ? -1 : ans) << endl;
        memset(cnt, 0, sizeof(cnt));
    }

}