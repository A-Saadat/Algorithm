#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000
#define forn(i,n) for(int i=1;i<=n;i++) 
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

intl a[def], pr[def];
intl sum[def];

int main (void)
{
    intl n, q; cin >> n >> q;
    forn(i,n) cin >> a[i];

    while(q--){
        intl x, y;
        cin >> x >> y;

        pr[x]++; pr[y + 1]--;
    }

    forn(i,n) sum[i] = sum[i - 1] + pr[i];
    sort(a + 1, a + n + 1); sort(sum + 1, sum + n + 1);

    intl ans = 0;
    forn(i,n) ans += a[i] * sum[i];

    cout << ans;

}