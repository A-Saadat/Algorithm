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
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 
int n = 10;

int a[10][10] = { {1,1,1,1,1,1,1,1,1,1}, {1,2,2,2,2,2,2,2,2,1}, {1,2,3,3,3,3,3,3,2,1}, {1,2,3,4,4,4,4,3,2,1}, {1,2,3,4,5,5,4,3,2,1}, {1,2,3,4,5,5,4,3,2,1}, {1,2,3,4,4,4,4,3,2,1}, {1,2,3,3,3,3,3,3,2,1}, {1,2,2,2,2,2,2,2,2,1}, {1,1,1,1,1,1,1,1,1,1}}; 
char b[20][20];

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                cin >> b[i][j];
                if(b[i][j] == 'X') ans += a[i][j];
            } 

        cout << ans << endl;
        
    }

}