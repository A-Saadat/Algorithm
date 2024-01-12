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

const int MAX = 1e3 + 10; 
const int INF = 1e9 + 7; 

int a[MAX][MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        vector<int> ans(MAX, (1 << 30) - 1);
        int n; cin >> n;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) cin >> a[i][j];

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) continue;

                ans[i] &= a[i][j]; 
            }
        }


        bool isOk = 1;
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++){
                if(i == j) continue;

                if((ans[i] | ans[j]) != a[i][j]) isOk = 0;
            }


        if(isOk){
            cout << "YES\n";        
            for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
            cout << endl;
        } 
        else{
            cout << "NO\n";
        }
    }

}