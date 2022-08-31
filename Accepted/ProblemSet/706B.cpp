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

vci a;

int main (void)
{
    intl n; cin >> n;
    forn(i,n){
        intl x; cin >> x;
        a.pb(x);
    }
    sort(a.begin(), a.end());

    intl q; cin >> q;

    forn(i,q){
        intl m; cin >> m;

        intl L = -1, R = a.size();

        while(R - L > 1){
            intl MID = L + ((R - L) / 2);

            if(a[MID] > m)
                R = MID;
            elif(a[MID] <= m){
                L = MID;
            }
        }

        cout << L + 1 << endl;
    }
}