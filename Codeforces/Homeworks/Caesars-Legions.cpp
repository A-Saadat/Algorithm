// ! I AM NOT INSANE
#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 

const int MOD = 1e8;

int dp[110][110][20][20]; // ? the number of sequences with i footman, j horseman and we can add atmost x footman and y horseman

main()
{IOS;

    int n1, n2; cin >> n1 >> n2;
    int k1, k2; cin >> k1 >> k2;

    for(int i = 0; i <= n1; i++){

        for(int j = 0; j <= n2; j++){

            for(int x = 0; x <= k1; x++){
                
                for(int y = 0; y <= k2; y++){
                    int sum = 0;
                    if(i + j == 0) sum = 1; // ? base of the dp

                    if(i > 0 && x > 0) sum += dp[i - 1][j][x - 1][k2], sum %= MOD;
                    if(j > 0 && y > 0) sum += dp[i][j - 1][k1][y - 1], sum %= MOD;

                    dp[i][j][x][y] = sum;

                    // cout << "dp[" << i << "][" << j << "][" << x << "][" << y << "] = " << dp[i][j][x][y] << endl;
                }
 
            }

        }

        // cout << "\n-----------------\n";

    }    


    cout << dp[n1][n2][k1][k2] << endl;
}