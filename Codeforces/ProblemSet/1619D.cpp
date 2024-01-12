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
typedef vector<int> vi;

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

vector<int> a[MAX];
int m, n; 

inline bool check(int x){
    vector<bool> able(m);
    bool isOk = 0;
    for(int i = 1; i <= m; i++){
        int c = 0;
        for(int j = 0; j < n; j++){
            if(a[i][j] < x) continue;

            able[j] = 1;
            c++;
        }
        if(c > 1) isOk = 1;
    }
    if(!isOk && m > 1) return 0;

    int ans = 1;
    for(int i = 0; i < n; i++)
        ans = ans && able[i];

    return ans;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> m >> n;
        for(int i = 1; i <= m + 100; i++) a[i].clear();
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int x; cin >> x;
                a[i].pb(x);
            }
        }

        int L = 1, R = 2;
        while(check(R)) R *= 2;
        while(R - L > 1){
            int mid = (R + L) / 2;
            if(check(mid)) L = mid;
            else R = mid;
        }

        cout << L << endl;
    }

}