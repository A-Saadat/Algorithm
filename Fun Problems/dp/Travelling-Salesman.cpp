// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 100; 
const ll INF = 1e9 + 7; 

int dp[MaxN][MaxN], val[MaxN][MaxN]; 
int n, m; 

void Update_dp(int S){ // ? the S is a Binary number that every "on bit" like <i>, will represent that the number i, is On the Set of Numbers that we are checking
    cout << S << " -> ";
    forn(i,0,10) cout << ((S >> i) & 1);
    cout << endl;
    
    forn(i,1,n + 1){

        if(dp[S][i]) continue;

        if( !((S >> (i - 1)) & 1) ) { // ? if the Number i, doesn't exist in S 
            dp[S][i] = -INF; // * this dp is not allowed because it will never happend
            continue;
        }
        int Sp = S ^ (1 << (i - 1)); // ? we made a new set and this time, it is NOT contain i

        int mini = INF; 
        forn(j,1,n + 1){
            if(i == j) continue;

            mini = min( dp[Sp][j] + val[i][j], mini );
        }

        dp[S][i] = mini;
        cout << "dp[" << S << "][" << i << "] = " << dp[S][i] << endl;

    }

    cout << "\n---------\n";

}

main()
{IOS;

    cin >> n >> m;
    while(m--){
        int u, v, vl; cin >> u >> v >> vl;
        val[u][v] = vl;
        val[v][u] = vl;
    }

    for(int mask = 1; mask < (1 << n); mask++){
        if((mask & 1) && __builtin_popcount(mask) == 2){
            
            int idx = -1;
            forn(i,1,32)
                if( (mask >> i) & 1 ) idx = i + 1;

            dp[mask][idx] = val[idx][1];
            // cout << mask << " -> " << idx << ": " << dp[mask][1] << endl;

        }
    }

    for(int mask = 1; mask < (1 << n); mask++)
        Update_dp(mask); // ? for every set of numbers we will find the answer

    cout << "\n\n ==> " << dp[ (1 << n) - 1 ][1];

}


// ** cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;

    // cout << S << ": ";
    // forn(i,0,10) cout << ((S >> i) & 1);
    // cout << "\n\n";