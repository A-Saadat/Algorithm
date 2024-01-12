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
#define err_dp(i, j) cout << "a[" << i << "][" << j << "] = " << (char)a[i][j] << endl;
#define int long long 

const int MAX = 50 + 10; 
const int INF = 1e9 + 7; 

int a[MAX][MAX]; 
int n, m; 

int sz_finder(int x, int y){
    // cout << x << " " << y << endl;

    int mini = INF, cnt = 0;
    for(int i = x - 1, j = y - 1; (i >= 1 && j >= 1 && a[i][j] == 92); i--, j--) cnt++;
    // cout << (char)(92) << " -> " << cnt << endl;
    mini = min(mini, cnt); cnt = 0;
    for(int i = x + 1, j = y + 1; (i <= n && j <= m && a[i][j] == 92); i++, j++) cnt++;
    // cout << (char)(92) << " -> " << cnt << endl;
    mini = min(mini, cnt); cnt = 0;

    // cout << "\n-----------\n";

    // ? "\"

    for(int i = x + 1, j = y - 1; (i <= n && j >= 1 && a[i][j] == 47); i++, j--) cnt++;
    // cout << "/ -> " << cnt << endl;
    mini = min(mini, cnt); cnt = 0;
    for(int i = x - 1, j = y + 1; (i >= 1 && j <= m && a[i][j] == 47); i--, j++) cnt++;
    // cout << "/ -> " << cnt << endl;
    mini = min(mini, cnt); cnt = 0;

    // cout << "\n-----------\n";

    // ? "/"

    for(int i = x, j = y + 1; (j <= m && a[i][j] == 45); j++) cnt++;
    // cout << "- -> " << cnt << endl;
    mini = min(mini, cnt); cnt = 0;
    for(int i = x, j = y - 1; (j >= 1 && a[i][j] == 45); j--) cnt++;
    // cout << "- <- " << cnt << endl;
    mini = min(mini, cnt); cnt = 0;
    // cout << "\n------------\n";

    // ? "-"

    for(int i = x + 1, j = y; (i <= n && a[i][j] == 124); i++) cnt++;
    // cout << "| -> " << cnt << endl;
    mini = min(mini, cnt); cnt = 0;
    for(int i = x - 1, j = y; (i >= 1 && a[i][j] == 124); i--) cnt++;
    // cout << "| <- " << cnt << endl;
    mini = min(mini, cnt); cnt = 0;

    // cout << "\n---------\n";
    // cout << mini << endl;
    return mini;

}

main()
{IOS;

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c; cin >> c;
            a[i][j] = (int)c;
        } 

    } 

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 43) // ? +
                ans = max(ans, sz_finder(i, j));
            // cout << a[i][j] << ' ';
        }
        // cout << endl;
    }

    cout << ans << endl;
}