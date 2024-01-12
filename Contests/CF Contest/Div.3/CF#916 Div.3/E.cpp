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
const int INF = 1e18 + 7; 

int a[MAX], b[MAX]; 
int mark[MAX], per[MAX];
int n;
int ans =-INF, res;

void BT(int id){
    if(id == n + 1){
        // check();

        // for(int i = 1; i <= n; i++) cout << per[i] << ' ';
        // cout << endl;
        // cout << 
        int sum = res;
        for(int i = 1; i <= n; i++){
            if(i % 2){
                sum += b[per[i]];
            }
            else{
                sum -= a[per[i]];
            }
        }

        // cout << res << endl;

        cout << "-> " << sum << endl;
        // cout << "\n--------------\n";
        ans = max(ans, sum);
        return;
        
    }

    // vector<int> v;
    for(int i = 1; i <= n; i++){
        if(mark[i]) continue;
        mark[i] = 1;
        per[id] = i;
        BT(id + 1);
        mark[i] = 0;
    }
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i], res += a[i];
        for(int i = 1; i <= n; i++) cin >> b[i], res -= b[i];

        cout << "res " << res << endl;

        BT(1);
        cout << "ans: " << ans << endl;
    }

}