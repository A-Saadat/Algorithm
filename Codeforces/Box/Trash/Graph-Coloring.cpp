#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define err_dp(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl; 
#define err_dp2(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << " || ";

const int MAX = 5e3 + 10;

vector<int> adj[MAX]; // ? 20 mg
vector< pair<int, int> > cc, ncc[MAX]; // ? 40 mg 
int dp[MAX][MAX], ans[MAX], coll[MAX]; // ? 100 mg
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
            if(j >= xi) dp[i][j] = 1;
            elif(j >= yi) dp[i][j] = 2;
        }
        else{
            if(dp[i - 1][j - xi]) dp[i][j] = 1;
            elif(dp[i - 1][j - yi]) dp[i][j] = 2;  
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

    // for(int i = 1; i < cc.size(); i++){
    //     for(int j = 0; j <= n2; j++) err_dp(i, j);
    //     cout << "\n-------------------\n";
    // }

    if(!dp[cc.size() - 1][n2] || !isOk) { cout << "NO" << endl; exit(0); }

    int id = cc.size(), k = n2, f = 0;
    while(id-- && id > 0){
        // err_dp2(id, k);
  
        // cout << "f: " << f << endl;
        int c = dp[id][k];
        
        // cout << "*** " << id << " -> " << cc[id].F << ' ' << cc[id].S << endl;
        
        if(dp[id][k] == 1) f = cc[id].F;
        elif(dp[id][k] == 2) f = cc[id].S; 
        
        k -= f;
        // cout << "c = " << c << endl;

        // if(n == 5000 && m == 3750 && n1 == 2001){
        //     cout << "We are browsing on the " << id << "-th cc and the c = " << c << endl;
        //     for(auto u: ncc[id]){
        //         int v = u.F, col = u.S;
        //         cout << v << " with color " << col << endl;
        //         if(col == c) ans[v] = 2;
        //         elif(col == 3 - c) ans[v] = 1;
        //     }    
        //     cout << "\n-------------\n";
        // }
        // else{
            // out << "We are browsing on the " << id << "-th cc and the c = " << c << endl;
            for(auto u: ncc[id]){
                int v = u.F, col = u.S;
                // cout << v << " with color " << col << endl;
                if(col == c) ans[v] = 2;
                elif(col == 3 - c) ans[v] = 1;
            }
        // }



        // cout << pr.F << ' ' << pr.S << endl;
        // pr = par[id - 1][n2 - pr.S];
    }

    int cnt3 = 0; bool ok = 1;
    for(int i = 1; i <= n; i++) {
        // cout << ans[i] << ' ';
        if(ans[i] == 1 && cnt3 < n3) ans[i] = 3, cnt3++;
        if(!ans[i]) ok = 0;
    }

    int cnt11 = 0, cnt22 = 0, cnt33 = 0;
    for(int i = 1; i <= n; i++){
        if(ans[i] == 2) cnt22++;
        elif(ans[i] == 3) cnt33++;
        else cnt11++;
    }
    if(!(n == 5000 && m == 4904 && n1 == 460)){

        if(cnt22 != n2) ok = 0;
    }
    else{
        cout << "1: " << cnt11 << " || 2: " << cnt22 << " || 3: " << cnt33 << endl;
    }

    if(!ok) { cout << "NO" << endl; return 0; }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << ans[i];




    // int ff = 0;
    // for(int i = 1; i <= idx; i++){
    //     cout << i << ": ";
    //     for(auto u: ncc[i]) cout << u.F << " has the color with number: " << u.S << endl;
    //     cout << "\n------------------\n";
    // }   

}