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

int main (void)
{
    intl n, k; cin >> n >> k;

    intl p = 0, cnt = 0;
    forn(i,n){
        p += i * 5;
        if(p + k <= 240) cnt++;
    }

    cout << cnt;
}