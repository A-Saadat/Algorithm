#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define msi map<string, int> 
#define mci map<char, int> 
#define si set<int> 
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

intl a[def];
vci p;

int main (void)
{   
    intl n, l, r, x; cin >> n >> l >> r >> x;
    forn(i,n) cin >> a[i];
    
    intl cnt = 0; 
    for(intl mask = 1; mask < (1 << n); mask++){
        p.clear();

        forn(j,n){
            if((mask >> j) & 1) p.pb(a[j]);
        }

        if(p.size() <= 1) continue;
        
        sort(p.begin(), p.end());
        intl max = p[p.size() - 1], min = p[0];

        intl sum = 0;
        forn(i,p.size()) sum += p[i];

        if(sum <= r and sum >= l and (max - min) >= x) cnt++;

    }

    cout << cnt;
}