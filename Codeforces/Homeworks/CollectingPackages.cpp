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

vpii path;

int main (void)
{
    intl t; cin >> t;
    while(t--){
        path.clear();

        intl n; cin >> n;
        while(n--){
            intl a, b;
            cin >> a >> b;
            path.pb(mp(a,b)); 
        }

        sort(path.begin(), path.end());

        bool isPossible = true;
        forn(i,(path.size() - 1)){
            if(path[i].F > path[i + 1].F || path[i].S > path[i + 1].S){
                isPossible = false;
                break;
            }
        }

        if(!isPossible){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        pii current = mp(0,0);

        forn(i,path.size()){
            intl RCnt = path[i].F - current.F;
            intl UCnt = path[i].S - current.S;

            while(RCnt--) cout << "R";
            while(UCnt--) cout << "U";

            current.F = path[i].F; current.S = path[i].S; 
        }

        cout << endl;

    }
}