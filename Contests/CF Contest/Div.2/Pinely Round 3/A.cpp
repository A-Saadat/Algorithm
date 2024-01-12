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
        int n; cin >> n;
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        for(int i = 1; i <= n; i++){
            int x, y; cin >> x >> y;
            if(x < 0) c1++;
            elif(x > 0) c2++;

            if(y > 0) c3++;
            elif(y < 0) c4++;
        }

        if(c1 * c2 * c3 * c4 != 0) cout << "NO\n";
        else cout << "YES\n";
    }

}