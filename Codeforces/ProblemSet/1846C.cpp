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

struct info{
    int idx;
    int slv;
    int pnlt;
};

int a[MAX], sum[MAX]; 
vector<int> v;
vector<info> ans;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, m, h; cin >> n >> m >> h;
        info Rudolf; int cnt = 0;
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n; i++){
            v.clear();
            for(int j = 1; j <= m; j++) cin >> a[j];
            sort(a + 1, a + m + 1);
            for(int j = 1; j <= m; j++){
                a[j] = a[j] + a[j - 1];
                sum[j] = sum[j - 1] + a[j];
                v.pb( a[j] );

            } 
            
            int slv = (upper_bound(all(v), h) - v.begin());
            int pnlt = sum[slv];

            ans.pb( {i, slv, pnlt} );

            if(i == 1)
                Rudolf = {i, slv, pnlt};
            else{
                if(slv > Rudolf.slv) cnt++;
                elif(slv == Rudolf.slv && pnlt < Rudolf.pnlt) cnt++;
            }
        }

        cout << cnt + 1 << endl;
    }
}