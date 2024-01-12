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
#define err_dp_MaxEl(i, j) cout << "dp_MaxEl[" << i << "][" << (i + (1 << j)) << "] = " << dp_MaxEl[i][j].F << " and the index of this El is " << dp_MaxEl[i][j].S << endl;
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

pair<int, int> dp_MaxEl[MAX][30];
int a[MAX], dp[MAX]; 
int n; 

inline void Update_dp_MaxEl(){
    for(int i = 1; i < n; i++){
        if(a[i] > a[i + 1]){
            dp_MaxEl[i][0].F = a[i];
            dp_MaxEl[i][0].S = i;
        }
        else{
            dp_MaxEl[i][0].F = a[i + 1];
            dp_MaxEl[i][0].S = i + 1;
        }
    }

    for(int k = 1; k <= 22; k++){
        for(int i = 1; (i + (1 << k)) <= n; i++){
            auto d1 = dp_MaxEl[i][k - 1];
            auto d2 = dp_MaxEl[i + (1 << (k - 1))][k - 1];

            if(d1.F > d2.F){
                dp_MaxEl[i][k].F = d1.F;
                dp_MaxEl[i][k].S = d1.S;
            }
            else{
                dp_MaxEl[i][k].F = d2.F;
                dp_MaxEl[i][k].S = d2.S;
            }
            // dp_MaxEl[i][k] = max(dp_MaxEl[i][k - 1], dp_MaxEl[i + (1 << (k - 1))][k - 1]);   
        }
    }

    // for(int k = 0; k <= 22; k++){
    //     for(int i = 1; (i + (1 << k)) <= n; i++){
    //         err_dp_MaxEl(i, k);
    //     }
    //     cout << "\n-----------------\n";
    // }
}

inline int RMQ(int L, int R){
    int sum = 0, m = 0;
    for(int k = 22; k >= 0; k--){
        if(L + (1 << k) > R) continue;
        cout << L << " - ";

        if(sum < dp_MaxEl[L][k].F){
            sum = dp_MaxEl[L][k].F;
            m = dp_MaxEl[L][k].S;
        }

        // ans = max(ans, dp_MaxEl[L][k]);
        L += (1 << k);
    }

    if(sum < a[R]){
        m = R;

    // cout << "\n-------------------------------------------------------------------------\n";
    return m;
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i < n; i++) cin >> a[i];
    Update_dp_MaxEl();

    dp[n] = 0;
    dp[n - 1] = 1; 
    for(int i = n - 2; i >= 1; i--){
        int m = RMQ(i + 1, a[i]);
        // cout << i << ": " << m << endl;
        int m = Find_MAX_El(i + 1, a[i]);
        dp[i] = dp[m] - (a[i] - m) + n - i;
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) ans += dp[i];

    cout << ans << endl;

}