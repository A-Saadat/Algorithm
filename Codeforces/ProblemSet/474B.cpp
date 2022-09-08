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

intl w[def];
intl sum[def];

int main (void)
{
    intl n; cin >> n;
    forn(i,n) cin >> w[i];
    forn(i,n) sum[i] = sum[i - 1] + w[i];

    intl q; cin >> q;

    while(q--){
        intl x; cin >> x;
        intl L = -1, R = n;

        while(R - L > 1){

            intl MID = L + ((R - L) / 2);

            if(sum[MID] >= x) R = MID;
            elif(sum[MID] < x) L = MID;

        }

        cout << R + 1 << endl;

    }
}