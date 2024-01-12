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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        if(k > 3) cout << "0\n";
        elif(k == 1) cout << "1\n";
        elif(k == 2){
            int sum = min(n, m);
            int x = max(0, (m / n) - 1);
            cout << sum + x << endl;
        }
        elif(k == 3){
            int sum = max(m - n, 0);
            int x = max(0, (m / n) - 1);
            cout << sum - x << endl;
        }
    }

}