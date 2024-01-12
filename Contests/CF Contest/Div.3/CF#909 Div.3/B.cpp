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

const int MAX = 150e3 + 10; 
const long long INF = 1e18 + 10; 

int a[MAX]; 
vector<long long> ps(MAX);

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i], ps[i] = ps[i - 1] + a[i];
        int lim = n / 2;
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            if(n % i) continue;
            
            long long maxi = 0, mini = INF;
            for(int j = i; j <= n; j += i){
                maxi = max(maxi, ps[j] - ps[j - i]);
                mini = min(mini, ps[j] - ps[j - i]);
            }
            
            ans = max(ans, maxi - mini);
        }

        cout << ans << endl;

    } 

}