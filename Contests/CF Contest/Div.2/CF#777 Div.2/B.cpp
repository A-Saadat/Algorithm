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
// #define int long long 

const int MAX = 100 + 50; 
const int M = 1e4 + 10;
const int INF = 1e9 + 7; 

string s[MAX];
char a[MAX][MAX];
vector<pair<int, int>> v[M];
int mark[MAX][MAX];
int n, m, cnt; 

int G[5] = {-1, +1, 0, 0};
int H[5] = {0, 0, +1, -1};

void dfs(int x, int y){
    v[cnt].pb(make_pair(x, y)); mark[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int xx = x + G[i];
        int yy = y + H[i];

        if(a[xx][yy] == '0' || mark[xx][yy]) continue;
        if(xx > n || xx <= 0 || yy > m || yy <= 0) continue;

        dfs(xx, yy);
    }
}

inline void Solve(){
    cnt = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s[i];

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++) a[i][j + 1] = s[i][j];
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) mark[i][j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            if(!mark[i][j] && a[i][j] != '0'){
                cnt++;
                v[cnt].clear();
                dfs(i, j);
            }
        }
    }

    for(int i = 1; i <= cnt; i++) sort(all(v[i]));

    bool isOk = 1;
    for(int i = 1; i <= cnt; i++){
        int x1 = v[i][0].F, y1 = v[i][0].S;
        int x2 = v[i].back().F, y2 = v[i].back().S;

        int sz = (x2 - x1 + 1) * (y2 - y1 + 1);

        bool isN = 1;
        for(auto [x, y]: v[i]){
            if(x < x1 || x > x2) isN = 0;
            if(y < y1 || y > y2) isN = 0;
        } 

        if(sz != v[i].size()) isN = 0;

        if(!isN) {isOk = 0; break;}
    }

    if(isOk) cout << "YES\n";
    else cout << "NO\n";
}

signed main()
{IOS;

    int t; cin >> t;
    while(t--){
        Solve();
    }

}