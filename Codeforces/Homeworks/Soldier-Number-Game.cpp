// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false) 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define elif else if 
typedef long long int ll; 
typedef map<string, ll> msi;  
typedef map<char, ll> mci; 
typedef map<ll, ll> mll; 
typedef set<ll> si;  
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<ll,ll> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const int MAXN = 5e6;

int dp[MAXN + 5] ;
int sum[MAXN + 5];
vci Prime;
int notPrime[MAXN + 5];

void findPrime(int x){
    vci primeNum;

    for(int i = 2; i * i <= x; i++){
        if(notPrime[i]) continue;
        for(int j = i * i; j <= x; j+=i){
            notPrime[j] = i;
        }
    }
}

void DPF(int n){
    forn(i,2,n + 1){
        int tmp = i, cnt = 0, idx = 0;
        
        if(!notPrime[i]) continue;

        dp[i] = dp[i / notPrime[i]] + 1;
    }
}

main ()
{IOS; cin.tie(); cout.tie();
    dp[0] = 0; dp[1] = 0;
    
    findPrime(MAXN);
    forn(i,2,MAXN + 1) 
        if(!notPrime[i]) dp[i] = 1;
    DPF(MAXN + 1);
    
    forn(i,0,MAXN + 1) sum[i] = sum[i - 1] + dp[i];
    int t; scanf("%d", &t);
    while(t--){
        int a, b; scanf("%d%d", &a, &b);

        printf("%d\n", (sum[a] - sum[b]));
    }
}