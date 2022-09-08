#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define elif else if 
typedef long long int intl; 
typedef vector<intl> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

const intl MOD = 1e9+7;

int main (void)
{
    intl t; cin >> t;
    
    while(t--){
        intl n, k; cin >> n >> k;

        intl ans = 0, pow = 1;
        forn(i,31){
            if((k >> i) & 1 == 1)
                ans = (ans + pow) % MOD;

            pow *= n;
            pow %= MOD;
        }

        cout << ans % MOD << endl;
    }
}