#include <bits/stdc++.h> 
using namespace std; 

#define def 2*100000
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

intl a[def], ans, cnt;

int main (void)
{
    intl n, k; cin >> n >> k;
    forn(i,n) cin >> a[i];
    sort(a, a + n);
    
    if(k == 0) ans = a[0] - 1;
    else ans = a[k - 1];

    forn(i,n) if(a[i] <= ans) cnt++;

    if(cnt != k or !(ans >= 1 and ans <= 10e9)){
        cout << "-1";
        return 0;
    }

    cout << ans;
}