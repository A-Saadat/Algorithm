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
typedef vector<char> vc; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

vc a; vc b;

int main (void)
{
    intl t; cin >> t;
    
    while(t--){

        a.clear(); b.clear();

        intl n; cin >> n;
        forn(i,n){
            char tmp; cin >> tmp;
            a.pb(tmp);
        }
        forn(i,n){
            char tmp; cin >> tmp;
            b.pb(tmp);
        }

        bool flag = true;
        forn(i,n){

            if(a[i] == 'R'){
                if(b[i] != 'R'){
                    cout << "NO" << endl;
                    // cout << "It's Not Match for R: " << i << endl;

                    flag = false;
                    break;
                }
            }
            elif(a[i] == 'B' or a[i] == 'G'){
                if(b[i] == 'R'){
                    cout << "NO" << endl;
                    // cout << "It's Not Match for GB" << endl;
                    flag = false;
                    break;
                }
            }

        };

        if(flag) cout << "YES" << endl;

    }
}