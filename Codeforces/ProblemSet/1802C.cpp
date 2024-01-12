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

const int MAX = 256 + 10; 
const int INF = 1e9 + 7; 

int mat[MAX][MAX]; 

main()
{IOS;

    int cnt = 0;
    for(int i = 0; i < 256; i+=2){
        for(int j = 0; j < 256; j+=2){
            mat[i][j] = cnt;
            mat[i][j + 1] = cnt + 1;
            mat[i + 1][j] = cnt + 2;
            mat[i + 1][j + 1] = cnt + 3;

            cnt += 4;
        }
    }

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        cout << n * m << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << mat[i][j] << ' ';
            cout << endl;
        }
    }

}   