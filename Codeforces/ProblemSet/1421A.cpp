#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
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

vci v;

int main (void)
{
    intl t;
    cin >> t;

    intl copy = t;

    while(copy--){
        intl a, b;
        cin >> a >> b;

        v.pb((a ^ (a&b)) + (b ^ (a&b))); 
    }

    forn(i,t) cout << v[i] << endl;
}