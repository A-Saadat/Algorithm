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
const int INF = 1LL * 1000 * 1000 * 10000; 

int a[MAX]; 
vector<int> v1, v2;

main()
{IOS;

    int n, m; cin >> n >> m;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i == 2){
            ans += max(1LL * 0, a[1] - a[2]);
            a[2] += max(1LL * 0, a[1] - a[2]);
        }
        if(i > 2) {
            if(a[i] >= a[1] && a[i] <= a[2]) m--;
            elif(a[i] > a[2]) v1.pb(a[i]);
            else v2.pb(a[i]);
        }
    }

    sort(all(v1));
    sort(all(v2), greater<int>());
    
    if(m <= 0) cout << 0 << endl;
    else{
        int mini = INF, sum = 0;;
        for(int i = 0; i <= min((int)(v2.size()), m); i++){
            if(m - i > v1.size()) continue;
            if(i != m) sum = v1[m - i - 1] - a[2];
            if(i) sum += a[1] - v2[i - 1];
            mini = min(mini, sum);
        }

        cout << (mini == INF ? 0 : mini) + ans << endl;
    }
    



}