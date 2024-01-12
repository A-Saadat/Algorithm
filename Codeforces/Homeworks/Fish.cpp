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
// #define err_dp(mask)
#define int long long 

const int MAX = 18 + 2; 
const int M = (1 << 18) + 10;
const int INF = 1e9 + 7; 

double a[MAX][MAX], dp[M]; 

main()
{IOS;   
    cout.precision(12); cout.setf(ios::fixed);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    dp[ (1 << n) - 1 ] = 1.0;
    for(int mask = (1 << n) - 2; mask >= 0; mask--){
        vector<int> O, Z;
        int tmp = mask;
        for(int j = 0; j < n; j++){
            if((tmp >> j) & 1) O.pb(j);
            else Z.pb(j);
        }

        int blp = O.size();
        int chs = (blp * (blp + 1)) / 2;

        double sum = 0.0;
        for(int o: O)
            for(int z: Z)
                sum = sum + (a[o][z] * dp[mask ^ (1 << z)] / chs);

        dp[mask] = sum;
    }

    for(int i = 0; i < n; i++)
        cout << dp[(1 << i)] << ' ';

}