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
const int INF = 1e18 + 100; 

int a[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int minel = INF;
        for(int i = 1; i <= n; i++) cin >> a[i], minel = min(minel, a[i]);

        int mini = INF;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                mini = min(mini, abs(a[i] - a[j]));
            }
        }

        if(k >= 3) cout << "0\n";
        elif(k == 1) cout << min(minel, mini) << endl;
        else{
            // mini = min(mini, minel);
            int mini2 = INF;
            for(int i = 1; i <= n; i++){
                mini2 = min(mini2, abs(mini - a[i]));
            }

            cout << min({minel, mini, mini2}) << endl;
        }
    }

}