#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define err_dp(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << " -> " << par[i][j].F << ' ' << par[i][j].S << endl; 
#define err_dp2(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << " || ";

const int MAX = 5e3 + 10;

vector<int> adj[MAX]; // ? 20 mg
vector< pair<int, int> > cc, ncc[MAX]; // ? 40 mg 
pair<int, int> par[MAX][MAX]; // ? 200 mg

int dp[MAX][MAX], ans[MAX], coll[MAX]; // ? 120 mg
int a, b, n, n1, n2, n3, m;

bool isOk = 1;
int idx;
void dfs(int v, int c){
    ncc[idx].pb( {v, c} ); coll[v] = c;
    if(c == 1) a++;
    else b++;

    for(int u: adj[v]){
        if(coll[v] == coll[u]) isOk = 0;
        if(coll[u]) continue;
        dfs(u, 3 - c);
    }
}

inline void Update_dp(int i){
    for(int j = 0; j <= n2; j++){
        int xi = cc[i].F, yi = cc[i].S;
        if(i == 1){ // ? it's about base of dp
            dp[i][j] = (j >= xi || j >= yi ? 1 : 0);
            if(j >= xi) par[i][j] = {1, xi};
            elif(j >= yi) par[i][j] = {2, yi};
        } 
        else{
            if(j >= max(xi, yi)){
                dp[i][j] = dp[i - 1][j - xi] + dp[i - 1][j - yi];
                // cout << "*** dp[" << i << "][" << j << "] = " << dp[i][j] << " will Update from -> ";
                // err_dp2(i - 1, j - xi); err_dp2(i - 1, j - yi);
                // cout << "\n---------------------\n";
            } 
            elif(j >= xi){
                dp[i][j] = dp[i - 1][j - xi];
                // cout << "** dp[" << i << "][" << j << "] = " << dp[i][j] << " will Update from -> ";
                // err_dp2(i - 1, j - xi);
                // cout << "\n---------------------\n";
            } 
            elif(j >= yi){
                dp[i][j] = dp[i - 1][j - yi];
                // cout << "* dp[" << i << "][" << j << "] = " << dp[i][j] << " will Update from -> ";
                // err_dp2(i - 1, j - yi);
                // cout << "\n---------------------\n";
            } 

            if(dp[i][j]) dp[i][j] = 1;

            if(dp[i - 1][j - xi]) par[i][j] = {1, xi};
            elif(dp[i - 1][j - yi]) par[i][j] = {2, yi};  
        }
    }
}

main()
{IOS;

    cc.pb({-1, -1}); // ? to making the vector, start from index 1

    cin >> n >> m;
    cin >> n1 >> n2 >> n3;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(int i = 1; i <= n; i++){
        if(coll[i]) continue;
        a = 0, b = 0;
        ++idx;
        dfs(i, 1);
        cc.pb( {a, b} );
    }
    // int idn = 0;
    // for(auto u: cc) cout << idn++ << ": " << u.F << " - " << u.S << endl;

    for(int i = 1; i < cc.size(); i++) Update_dp(i);

    for(int i = 1; i < cc.size(); i++){
        for(int j = 0; j <= n2; j++) err_dp(i, j);
        cout << "\n-------------------\n";
    }

    if(!dp[cc.size() - 1][n2] || !isOk) { cout << "NO" << endl; exit(0); }

    int id = cc.size(), k = n2;
    auto pr = par[id - 1][k];
    while(id-- && id > 0){
        err_dp2(id, k);
        cout << endl;
        int c = pr.F;
        cout << "c = " << c << endl;

        for(auto u: ncc[id]){
            int v = u.F, col = u.S;
            if(col == c) ans[v] = 2;
            else ans[v] = 1;
        }

        // cout << "\n-------------\n";

        // cout << pr.F << ' ' << pr.S << endl;
        k -= pr.S;
        pr = par[id - 1][n2 - pr.S];
    }

    int oneCNT = 0;
    for(int i = 1; i <= n; i++) {
        if(oneCNT >= n1 && ans[i] == 1) ans[i] = 3;
        if(ans[i] == 1) oneCNT++;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << ans[i];


    // int ff = 0;
    // for(int i = 1; i <= idx; i++){
    //     cout << i << ": ";
    //     for(auto u: ncc[i]) cout << u.F << " has the color with number: " << u.S << endl;
    //     cout << "\n------------------\n";
    // }
    

}