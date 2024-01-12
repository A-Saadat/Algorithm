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
#define err_dp(i, j, k) cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
#define err_par(ii, jj, kk) cout << "par[" << ii << "][" << jj << "][" << kk << "] = {" << par[ii][jj][kk].i << ", " << par[ii][jj][kk].j << ", " << par[ii][jj][kk].k << "}\n";
#define int long long 

const int MAX = 25 + 10; 
const int M = 25 * 50 * 1000; 
const int INF = 1e9 + 7; 


struct str{int i; int j; int k;};
vector<int> v;
int mat[5][MAX], dp[MAX][MAX][MAX];
str par[MAX][MAX][MAX];
int sum;
vector<int> sec;
map<int, int> mp;

// void Find_par(str p){
//     while(p.j > 0){
//         err_dp(p.i, p.j, p.k);
//         err_par(p.i, p.j, p.k);
//         int pre = p.j;
//         p = par[p.i][p.j][p.k];
//         if(p.j < pre) sec.pb(v[p.i]), mp[v[p.i]]--;
//     }

//     // for(int u: sec) cout << u << " ";
// }/

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= n; j++) {
            int x; cin >> x;
            v.pb(x);
            mp[x]++;
            sum += x;
        }
    }

    sort(all(v), greater<int>());
    mat[1][1] = *v.rbegin();
    sum -= mat[1][1];
    mp[mat[1][1]]--;
    v.pop_back();
    mat[2][n] = *v.rbegin();
    sum -= mat[2][n];
    mp[mat[2][n]]--;
    v.pop_back();

    dp[0][0][0] = 1;
    for(int i = 1; i <= 2 * (n - 1); i++){
        // cout << v[i - 1] << endl;
        for(int j = 0; j <= (n - 1); j++){
            for(int k = 0; k <= M; k++){
                dp[i][j][k] = dp[i - 1][j][k];
                par[i][j][k] = {i - 1, j, k};
                if(k - v[i - 1] >= 0 && j > 0){
                    dp[i][j][k] = dp[i][j][k] + dp[i - 1][j - 1][k - v[i - 1]];
                    if(dp[i - 1][j - 1][k - v[i - 1]])
                        par[i][j][k] = {i - 1, j - 1, k - v[i - 1]};
                } 
                dp[i][j][k] = (dp[i][j][k] > 0);
                // err_dp(i, j, k);
            }
            // cout << endl;
        }   
        // cout << "\n--------------------------\n";
    }

    // str p;
    // // cout << sum << endl;
    // for(int k = 0; k <= M; k++){
    //     // err_dp(2*(n - 1), n - 1, k);
    //     if(sum <= 2 * k && dp[2*(n - 1)][n - 1][k]){
    //         cout << "1";
    //         p = {2*(n - 1), n - 1, k};
    //         break;
    //     }
    // }

    // cout << p.i << ", " 

    // Find_par(p);
    // sort(all(sec));

    // vector<int> fr;
    // fort(itr, mp){
    //     if(itr->S > 0) {
    //         while(itr->S > 0){
    //             fr.pb(itr->F);
    //             mp[itr->F]--;
    //         }
    //     }
    // }

    // sort(all(fr), greater<int>());

    // // cout << endl;
    // // for(int u: sec) cout << u << ' ';

    // cout << mat[1][1] << ' ';
    // for(int u: fr) cout << u << " ";
    // cout << endl;
    // for(int u: sec) cout << u << " ";
    // cout << mat[2][n] << " ";

}