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
map<int, int> mp; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        mp.clear();
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            for(int j = 2; j <= MAX && x > 1; j++){
                // cout << j << ": " << x << endl;
                int cnt = 0;
                while(x % j == 0 && x > 0){
                    cnt++;
                    x /= j;
                }
                
                mp[j] += cnt;
            }
        }

        bool isOk = 1;
        fort(itr, mp){
            // cout << itr->F << ": " << itr->S << endl;
            if(itr->S % n) isOk = 0;
        }

        if(isOk) cout << "YES\n";
        else cout << "NO\n";   
    }    

}