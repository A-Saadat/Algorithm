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
#define err_dp(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;

const int MAX = 26;
const int M = MAX * 50 * 1000; 
const int INF = 1e9 + 7; 

vector<int> v;
int dp[M][MAX];
int sum;
map<int, int> mp;

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            v.pb(x);
            sum += x;
        }
    }

    sort(v.rbegin(), v.rend());
    int a1 = v.back();
    v.pop_back();
    int a2 = v.back();
    v.pop_back();

    sum -= a1 + a2;

    for(int s = 0; s <= M - 1; s++)
        for(int j = 0; j <= n; j++)
            dp[s][j] = -1;

    dp[0][0] = 0;
    for(int u: v){ // ? the reason that we start from M and go to 0 is because we are allowed to use any element at most once
        for(int s = M - 1; s >= 0; s--){
            for(int j = n - 1; j >= 1; j--){ // ? the same reasoning is true for this one
                if(s - u < 0) continue;
                if(dp[s][j] == -1 && dp[s - u][j - 1] != -1) 
                    dp[s][j] = u;
            }
        }
    }

    int res = 0;
    for(int s = (sum / 2); s <= M - 1; s++){
        if(dp[s][n - 1] == -1 || sum > 2 * s) continue;

        res = s;
        break;
    }

    
    vector<int> fr, sc;
    int cnt = n - 1;
    while(cnt > 0){
        mp[ dp[res][cnt] ]++;
        res -= dp[res][cnt];
        cnt--;
    }

    for(int u: v){
        if(mp[u] > 0){
            sc.pb(u);
            mp[u]--;
        }
        else
            fr.pb(u);
    }

    sort(sc.rbegin(), sc.rend());
    sort(all(fr));

    cout << a1 << ' ';
    for(int u: fr) cout << u << ' ';
    cout << "\n";
    for(int u: sc) cout << u << ' ';
    cout << a2;
}