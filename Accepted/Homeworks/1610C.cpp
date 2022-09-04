#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define msi map<string, int> 
#define mci map<char, int> 
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

vpii a;

int main (void)
{
    intl t; cin >> t;
    while(t--){
        a.clear();

        intl n; cin >> n;

        forn(i,n){
            intl x, y;
            cin >> x >> y;
            a.pb(mp(x,y));
        }

        intl L = -1, R = n + 1;
        while(R - L > 1){
            intl MID = L + ((R - L) / 2);
            intl p = 0;

            forn(i,n){
                intl x = a[i].F, y = a[i].S;

                if((MID - x - 1 <= p) and (p <= y)) p++;
            }

            if(p < MID) R = MID;
            elif(p >= MID) L = MID;
        }

        cout << L << endl;

    }   
}