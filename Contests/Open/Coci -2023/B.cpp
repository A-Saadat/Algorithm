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
#define err_dp(x, y, z) cout << "dp[" << x << "][" << y << "][" << z << "] = " << dp[x][y][z] << endl; 
#define int long long 

const int MAX = 100 + 10; 
const int INF = 1e9 + 7; 

int dp[MAX][MAX];
string tmp[MAX][MAX]; 
int a[MAX][MAX][MAX];

main()
{IOS;

    int n; cin >> n;
    int x1, y1, z1; cin >> x1 >> y1 >> z1;
    int x2, y2, z2; cin >> x2 >> y2 >> z2;

    // for(int z = 1; z <= n; z++){
    //     for(int x = 1; x <= n; x++){
    //         for(int y = 1; y <= n; y++){
    //             cin >> a[x][y][z];
    //         } 
    //     }
    // }

    for(int z = 1; z <= n; z++){
        for(int y = 1; y <= n; y++){
            cin >> tmp[z][y];
        }
    }

    cout << endl;
    for(int z = 1; z <= n; z++){
        for(int y = 1; y <= n; y++){
            // cout << tmp[z][y] << endl;
            for(int x = 1; x <= n; x++){
                a[z][y][x] = tmp[z][y][x - 1] - '0';
            }
        }

        // cout << "\n---------\n";
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) 
            dp[i][j] = INF;
    }

    


    // for(int x = 1; x <= n; x++){
    //     for(int y = 1; y <= n; y++){
    //         for(int z = 1; z <= n; z++){
    //             cout << a[x][y][z] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << "\n-------------\n";
    // }   

    // for(int x = 0; x <= n; x++)
    //     for(int y = 0; y <= n; y++)
    //         for(int z = 0; z <= n; z++) dp[x][y][z] = INF;

    // dp[1][1][1] = 0;
    // for(int z = 1; z <= n; z++){
    //     for(int y = 1; y <= n; y++){
    //         for(int x = 1; x <= n; x++) {
    //             int mini = min({dp[z - 1][y][x], dp[z][y - 1][x], dp[z][y][x - 1]});
    //             dp[z][y][x] = min(dp[x][y][x], mini + 1);
    //             err_dp(z, y, x);
    //         }
    //         cout << endl;
    //     }
    //     cout << "\n------------------\n";
    // }
    
}