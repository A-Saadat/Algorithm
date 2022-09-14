#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
#define forn(i,k,n) for(int i=k;i<n;i++) 
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
intl sum[def];

int main (void)
{
    intl n; cin >> n;
    forn(i,1,(n + 1)) cin >> a[i];
    sort(a, a + n);

    forn(i,1,(n + 1)) sum[i] = sum[i - 1] + a[i]; // array Sum
    
    intl cnt = 0;
    forn(i,1,(n + 1)){
        if(sum[i - 1] <= a[i]) cnt++;
    }

    cout << cnt;
}