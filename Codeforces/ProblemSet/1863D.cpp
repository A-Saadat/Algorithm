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

const int MAX = 500 + 10; 
const int INF = 1e9 + 7; 

vector<int> dv[MAX], dh[MAX]; // ? dh[i] = Horizontal Dominoes that starts in row with number i
char res[MAX][MAX];
int n, m; 

inline void Solve(){
    for(int i = 0; i < n; i++){
        int lim = dv[i].size() / 2;
        for(int j = 0; j < lim; j++){
            int u = dv[i][j];  
            res[i][u] = 'B';
            res[i + 1][u] = 'W';
        }
    }

    for(int i = 0; i < n; i++){
        int lim = dv[i].size() / 2;
        for(int j = lim; j < dv[i].size(); j++){
            int u = dv[i][j];  
            res[i][u] = 'W';
            res[i + 1][u] = 'B';
        }
    }

    for(int i = 0; i < m; i++){
        int lim = dh[i].size() / 2;
        for(int j = 0; j < lim; j++){
            int u = dh[i][j];
            res[u][i] = 'B';
            res[u][i + 1] = 'W';
        }
    }

    for(int i = 0; i < m; i++){
        int lim = dh[i].size() / 2;
        for(int j = lim; j < dh[i].size(); j++){
            int u = dh[i][j];
            res[u][i] = 'W';
            res[u][i + 1] = 'B';
        }
    }
}

inline void clearArr(){
    for(int i = 0; i < 510; i++) dv[i].clear();
    for(int i = 0; i < 510; i++) dh[i].clear();
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        clearArr();
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                 cin >> res[i][j];
            
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(res[i][j] == 'U') dv[i].pb(j);
                if(res[i][j] == 'L') dh[j].pb(i);
            }
        }
        
        bool isOk = 1;
        for(int i = 0; i < n; i++)
            if(dv[i].size() % 2) isOk = 0;

        for(int i = 0; i < m; i++)
            if(dh[i].size() % 2) isOk = 0;

        if(!isOk){
            cout << "-1\n";
            continue;
        }
        else{
            Solve();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++) cout << res[i][j];
                cout << endl;
            }
        }

    }

}