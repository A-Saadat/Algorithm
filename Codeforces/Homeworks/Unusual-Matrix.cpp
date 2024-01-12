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

int a[MAX][MAX], b[MAX][MAX]; 
struct edg{int rc; int cn; int num;}; // ? rc -> row / col, cn = main / counter main, num = the number of col / row

vector<edg> adj[3][3][MAX];
int mark[3][3][MAX];
int cmp[3][3][MAX];
int now = 0;
int n; 

void Add_edg(edg A, edg B){
    adj[A.rc][A.cn][A.num].pb(B);
    adj[B.rc][B.cn][B.num].pb(A);
}

void dfs(edg A){
    int rc = A.rc, cn = A.cn, num = A.num; cmp[rc][cn][num] = now;
    mark[rc][cn][num] = 1;
    for(auto x: adj[rc][cn][num]){
        if(mark[x.rc][x.cn][x.num]) continue;

        dfs(x);
    }
}

void _clear(){
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 1; j++)
            for(int k = 0; k <= 1; k++)
                mark[j][k][i] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 1; j++)
            for(int k = 0; k <= 1; k++)
                adj[j][k][i].clear();
    
    now = 0;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n;
        _clear();
        for(int i = 1; i <= n; i++){
            string s; cin >> s;
            for(int j = 0; j < n; j++) a[i][j + 1] = (s[j] - '0');
        }
        for(int i = 1; i <= n; i++){
            string s; cin >> s;
            for(int j = 0; j < n; j++) b[i][j + 1] = (s[j] - '0');
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][j] == b[i][j]){
                    Add_edg({0, 0, i}, {1, 0, j});
                    Add_edg({0, 1, i}, {1, 1, j});
                }
                else{
                    Add_edg({0, 0, i}, {1, 1, j});
                    Add_edg({0, 1, i}, {1, 0, j});
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= 1; j++){
                for(int k = 0; k <= 1; k++){
                    if(!mark[j][k][i]) now++, dfs({j, k, i});
                }
            }
        }

        bool isOk = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= 1; j++){
                if(cmp[j][0][i] == cmp[j][1][i]) isOk = 0;
            }
        }

        if(isOk) cout << "YES\n";
        else cout << "NO\n";
    }
}