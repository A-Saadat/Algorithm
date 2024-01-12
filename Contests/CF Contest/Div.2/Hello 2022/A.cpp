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

char a[50][50]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        if(k > ((n + 1) / 2)) cout << -1 << endl;
        else{
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++) a[i][j] = '.';
            }

            int cnt = 0;
            for(int i = 1; i <= n && cnt < k; i+=2){
                cnt++;
                a[i][i] = 'R';
            }

            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++) cout << a[i][j];
                cout << endl;
            }
        }
    }

}