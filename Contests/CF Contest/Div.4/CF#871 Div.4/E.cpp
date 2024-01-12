#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e3 + 100; 
const int INF = 1e9 + 7; 

int a[MAX][MAX], mark[MAX][MAX]; 

int G[] = {1, -1, 0, 0};
int H[] = {0, 0, 1, -1};

ll sum = 0;

void dfs(int i, int j){
    mark[i][j] = 1;
    cout << i << " -> " << j << endl;
    for(int i = 0; i < 4; i++){
        int xi = i + G[i];
        int yi = i + H[i];
        
        if()
    }
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) cin >> a[i][j];
    
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(mark[i][j] || a[i][j] == 0 ) continue;
                
                ans = max(ans, sum);
                sum = 0;
                dfs(i, j);
            }
        }
    }

}