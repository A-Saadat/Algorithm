// ! I AM NOT INSANE;
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

const int MaxN = 1e6; 
const int MOD = 1e9 + 7; 

int dp[MaxN], FD[MaxN]; // ? FD = First Divisor

void Find_FD(){
    forn(i,1,MaxN + 1) FD[i] = 1;

    for(int i = 2; i * i <= MaxN; i++){
        if(FD[i] > 1) continue;
        
        for(int j = i * i; j <= MaxN; j += i)
            if(FD[j] == 1) FD[j] = i;
    }
}

void Find_DP(){
    dp[1] = 1;
    forn(i,2,MaxN + 1)
        dp[i] = max(dp[i - 1], ( FD[i] == 1 ? 1 : gcd(i, i / FD[i]) ) );
}

main()
{IOS;

    Find_FD();
    Find_DP();

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << dp[n] << endl;
    }

}