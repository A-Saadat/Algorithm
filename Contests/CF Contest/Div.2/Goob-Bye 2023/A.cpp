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

int a[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int sum = 1;
        for(int i = 1; i <= n; i++) cin >> a[i], sum = sum * a[i];

        if((2023 % sum)) cout << "NO\n";
        else{
            cout << "YES\n";
            cout << 2023 / sum << " ";
            for(int i = 2; i <= k; i++) cout << 1 << " ";
            cout << endl;
        }
        
    }

}