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
typedef vector<int> vi;

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

int mark[MAX], dep[MAX]; 
vector<int> adj[MAX], resi[MAX]; // ? resi[i] = residents of vertex i
set<int> rr[MAX];

int n, m, q;
int par[MAX][30];
vector<int> dp[MAX][30]; // ? dp's containe at most 10 residents with the lowest id number

vector<int> merge( vector<int> A, vector<int> B, int id ){
    vector<int> ans;
    int a = A.size(), b = B.size();
    int i = 0, j = 0;

    int cnt = 0;
    while(cnt < 10 && i < a && j < b){
        if(mark[ A[i] ] == id){
            i++;
            continue;
        } 
        if(mark[ B[j] ] == id){
            j++;
            continue;
        } 

        if(A[i] > B[j]){
            mark[ B[j] ] = id;
            ans.pb(B[j]);
            j++;
        }
        else{
            mark[ A[i] ] = id;
            ans.pb(A[i]);
            i++;
        }
        cnt++;
    }


    while(cnt < 10 && i < a){
        if(mark[ A[i] ] == id){
            i++;
            continue;
        } 
        
        ans.pb(A[i]);
        i++;
        cnt++;
    }
    while(cnt < 10 && j < b){
        if(mark[ B[j] ] == id){
            j++;
            continue;
        } 
        
        ans.pb(B[j]);
        j++;
        cnt++;
    }

    return ans;
}

int merge_ID = 0;
void dfs(int v, int p){
    for(int i = 1; i <= 22; i++){
        par[v][i] = par[ par[v][i - 1] ][i - 1];
        dp[v][i] = merge( dp[v][i - 1], dp[ par[v][i - 1] ][i - 1], ++merge_ID );
    }

    for(int u: adj[v]){
        if(u == p) continue;

        dep[u] = dep[v] + 1;
        par[u][0] = v;
        dp[u][0] = merge(resi[u], resi[v], ++merge_ID);
        dfs(u, v);
    }
}

inline vector<int> Find_Ans(int v, int u){
    vector<int> ans;
    if(dep[v] > dep[u]) swap(u, v);

    for(int i = 22; i >= 0; i--){
        int x = par[u][i];
        if(dep[x] < dep[v]) continue;

        ans = merge(ans, dp[u][i], ++merge_ID);
        u = par[u][i];
    }

    if(u == v) return ans;

    for(int i = 22; i >= 0; i--){
        int x = par[u][i], y = par[v][i];

        if(x == y) continue;

        ans = merge(ans, dp[u][i], ++merge_ID);
        ans = merge(ans, dp[v][i], ++merge_ID);

        u = par[u][i];
        v = par[v][i];
    }

    ans = merge(ans, dp[u][0], ++merge_ID);
    ans = merge(ans, dp[v][0], ++merge_ID);

    // cout << "LCA = " << par[u][0] << endl;

    return ans;
}

main()
{IOS;

    cin >> n >> m >> q;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        rr[x].insert(i);
    }

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        fort(itr, rr[i]){
            resi[i].pb(*itr);
            ++cnt;
            if(cnt == 10) break;
        }
    }

    dep[1] = 1;
    dfs(1, 0);

    while(q--){
        int x, y, a; cin >> x >> y >> a;

        if(x == y){
            int cnt = 0;
            int sz = resi[x].size();
            cout << min(sz, a) << ' ';
            for(int u: resi[x]){
                cout << u << " ";
                cnt++;
                if(cnt == a) break;
            } 
            cout << endl;
            continue;
        }
        
        vector<int> ans = Find_Ans(x, y);
        int sz = ans.size();
        cout << min(sz, a) << ' ';
        int cnt = 0;
        for(int u: ans){
            cout << u << ' ';
            cnt++;
            if(cnt == a) break;
        } 
        cout << endl;
    }

}