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

const int MAX = 100; 
const int INF = 1e9 + 7; 

char a[MAX][MAX]; 
char s[5] = {'v', 'i', 'k', 'a'};

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) cin >> a[i][j];

        int cnt = 0;
        for(int i = 1; i <= m; i++){
            if(cnt >= 4) break;
            for(int j = 1; j <= n; j++){
                if(a[j][i] == s[cnt]){
                    // cout << "a[" << j << "][" << i << "] = " << a[j][i] << " -> s[" << cnt << "] = " << s[cnt] << endl;
                    cnt++;
                    break;
                } 
            }
        }

        cout << (cnt != 4 ? "NO\n" : "YES\n");
    }

}