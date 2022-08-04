#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define pb push_back 
#define F first 
#define S second 
typedef long long int intl; 
typedef vector<int> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vcp;

int main (void)
{
    intl n;
    cin >> n;

    vcp team;
    forn(i,n){
        pii a;
        cin >> a.F >> a.S;

        team.pb(a);
    }

    intl cnt = 0;
    forn(i,n)
        forn(j,n)
            if(team[i].F == team[j].S)
                cnt++;

    cout << cnt;
}