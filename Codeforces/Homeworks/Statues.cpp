#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++)
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define elif else if

char a[10][10];
int s[10][10][10], dp[100][10][10]; 

int G[] = {-1, +1, 0, 0, -1, +1, -1, +1, 0};
int H[] = {0, 0, -1, +1, -1, +1, +1, -1, 0};

void Update_dp(int counter, int i, int j){                
    int sum = 0;
    forn(k,0,9){
        if(i + G[k] > 8 || j + H[k] > 8) continue;
        if(i + G[k] < 1 || j + H[k] < 1) continue;
        if(s[counter - 1][i + G[k]][j + H[k]] == 1) continue;                                                
        if(s[counter - 1][i][j] == 1 && G[k] == 1 && H[k] == 0) continue; // ? it means that we shouldn't update the dp from a block that containes a statue

        sum += dp[counter - 1][i + G[k]][j + H[k]];
    }

    dp[counter][i][j] = (sum > 0 ? 1 : 0); 
}

main()
{IOS;

    forn(i,1,9)
        forn(j,1,9) cin >> a[i][j];

    forn(counter, 0, 10)
        forn(i,1,9)
            forn(j,1,9)
                if(a[i][j] == 'S' && i + counter <= 8) s[counter][i + counter][j] = 1;

    dp[0][8][1] = 1; // ? Base of the dp, it's where the maria start moving
    forn(counter, 1, 100)
        forn(i,1,9)
            forn(j,1,9){
                if(s[counter - 1][i][j] == 1) continue;
                Update_dp(counter, i, j);
            }

    forn(counter,0,100){
        if(dp[counter][1][8] == 1){
            cout << "WIN";
            return 0;
        } 
    }

    cout << "LOSE";
}
