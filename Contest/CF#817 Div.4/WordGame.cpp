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

vs a; vs b; vs c;
intl score[def];

int main (void)
{
    vector<vs> ref;
    intl t; cin >> t;

    while(t--){

        intl n; cin >> n;

        a.clear(); b.clear(); c.clear();

        forn(i,n){
            string x; cin >> x;
            a.pb(x);
        }
        forn(i,n){
            string x; cin >> x;
            b.pb(x);
        }
        forn(i,n){
            string x; cin >> x;
            c.pb(x);
        }

        ref.pb(a); ref.pb(b); ref.pb(c); 

        forn(i,n){
            intl cnt = 0;
            for(intl j = 0; j < n; j++){
                if(ref[i][j] == ref[i + 1][j]);
            }
            cout << endl;
        }


    }
}