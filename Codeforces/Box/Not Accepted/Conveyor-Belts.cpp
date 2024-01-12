#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define mp make_pair
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
typedef vector<int> vi;

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 
const int sq = 317;
    
char a[MAX][30];
pair<int, int> out[MAX][30];
int n, m, q; 
map<char, int> dx, dy;

inline bool in_or_out(int x, int y, int k){
    return (x >= (k * sq) + 1) && (x <= (k + 1) * sq) && (y >= 1) && (y <= m);
}

pair<int, int> go_find(int i, int j, int k){
    char c = a[i][j];
    int x = i + dx[c], y = j + dy[c];

    if(out[i][j] != make_pair(INF, INF)) return out[i][j];

    if(a[i][j] == '>' && a[x][y] == '<') return out[i][j] = {-1, -1};
    if(!in_or_out(x, y, k)) return out[i][j] = {x, y};
    return out[i][j] = go_find(x, y, k);
}

inline void _set(int k){ // ? k => block number
    int L = (k * sq) + 1, R = min( ((k + 1) * sq) + 1, n + 1);
    
    for(int i = L; i < R; i++)
        for(int j = 1; j <= m; j++) out[i][j] = {INF, INF};

    for(int i = L; i < R; i++){
        for(int j = 1; j <= m; j++) {
            char c = a[i][j];
            int x = i + dx[c], y = j + dy[c];

            if(!in_or_out(x, y, k)) out[i][j] = {x, y};
            else{
                if(c == '^' || c == '<') out[i][j] = out[x][y];
                else{
                    if(out[i][j] != make_pair(INF, INF)) continue;
                    go_find(i, j, k);
                } 
            }
        }
    }
}

inline void _get(int x, int y){
    while(x > 0 && y > 0 && y <= m){
        int x1 = out[x][y].F;
        int y1 = out[x][y].S;
        x = x1, y = y1;
    }

    cout << x << ' ' << y << endl; 
}

main()
{IOS;

    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) 
            cin >> a[i][j];
            
    dx['^'] = -1;
    dy['>'] = +1;
    dy['<'] = -1;

    for(int i = 0; i < n; i++) _set(i);

    while(q--){
        char t; cin >> t;
        if(t == 'A'){
            int x, y; cin >> x >> y;
            _get(x, y);
        }
        else{
            int x, y; cin >> x >> y;
            char c; cin >> c;
            a[x][y] = c;
            _set(x / sq);
        }
    }
}