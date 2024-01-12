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

// const int MAX = 1e6; 
const int INF = 1e9 + 7; 

// int a[MAX][MAX]; 
int n, m; 


main()
{IOS;

    int t; cin >> t;
    while(t--){
        int a[n + 10][m + 10], mat[n + 10][m + 10], ps[n + 10][m + 10];
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) {
                cin >> a[i][j];
                mat[i][j] = 0;
            }
        }

        int l = 3;

        for(int i = 0; i <= n + 1; i++)
            for(int j = 0; j <= m + 1; j++) ps[i][j] = 0;

        // ps[1][1] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                mat[i][j] = (a[i][j] >= l);
                ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + mat[i][j];
            } 
            
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++) cout << mat[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << "\n-------------------------\n";
        
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++) cout << ps[i][j] << ' ';
        //     cout << endl;
        // }

        bool isOk =0;
        for(int i = 1; i + l - 1 <= n; i++)
            for(int j = 1; j + l - 1 <= m; j++){
                int sum = ps[i][j] - ps[i + l - 1][j - 1] - ps[i - 1][j + l - 1] + ps[i - 1][j - 1];
                if(sum == 9) isOk = 1;
            } 

        if(isOk) cout << "YES\n";
        else cout << "NO\n";

        // for(int i = 1; i <= m)

    }

}