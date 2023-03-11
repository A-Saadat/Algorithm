// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 1e3 + 100; 
const ll INF = 1e3; 

int dp[MaxN][MaxN];
vector< pair<int, int> > par; 
char a[MaxN];

void Update_dp(int i, int L, int R){
    forn(j, L + INF, R + 1 + INF){
            if(a[i] == 'W'){
                dp[i][j] = ( dp[i - 1][j - 1] >= 1 ? 1 : 0);

                cout << "dp[" << i << "][" << j - INF << "] " << "= " << dp[i][j] << endl;
            } 
            elif(a[i] == 'D'){
                dp[i][j] = ( dp[i - 1][j] >= 1 ? 1 : 0);

                cout << "dp[" << i << "][" << j - INF << "] " << "= " << dp[i][j] << endl;
            } 
            elif(a[i] == 'L'){
                dp[i][j] = ( dp[i - 1][j + 1] >= 1 ? 1 : 0);

                // cout << "*L: " << i - 1 << ' ' << j - 1 << endl;
                cout << "dp[" << i << "][" << j - INF << "] " << "= " << dp[i][j] << endl;
            } 

            elif(a[i] == '?'){
                dp[i][j] = ( dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1] >= 1 ? 1 : 0);

                cout << "dp[" << i << "][" << j - INF << "] " << "= " << dp[i][j] << endl;
            }
            
        }
}

main()
{IOS;

    int n, k; cin >> n >> k;
    forn(i,1,n + 1) cin >> a[i];

    dp[0][INF] = 1;

    forn(i,1,n + 1){
        cout << i << ": \n";
        if(i == n) Update_dp(i, (-k), (k));
        else Update_dp(i, (-k + 1), (k - 1));
        cout << "\n---------\n";
    }

    int curr = 0;
    if(dp[n][INF + k]) curr = k;
    elif(dp[n][INF - k]) curr = -k;
    else { cout << "NO" << endl; return 0; }

    par.pb( {n, curr} );
    while(--n){
        forn(j,INF - k, INF + k){
            if(dp[n][j]) {
                par.pb( {n, (j - INF)} );
                break;
            }
        }
    }

    par.pb( {0, 0} );

    // int sz = par.size();
    // forn(i,0,sz - 1) {
    //     pair<int, int> curr = par[i], nx = par[i + 1];
    //     cout << curr.F << ' ' << curr.S << " || " << nx.F << ' ' << nx.S << endl;

    //     // if(curr.S - nx.S == -1) a[ curr.F ] = 'L', cout << a[ curr.F ];
    //     // elif(curr.S - nx.S == 0) a[ curr.F ] = 'D', cout << a[ curr.F ];
    //     // elif(curr.S - nx.S == +1) a[ curr.F ] = 'R', cout << a[ curr.F ];

    // }

    // forn(i,1,n + 1) cout << a[i];
}