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
typedef pair<string,string> pss; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

bool flag[2];

int main (void)
{
    string a, b, ref;
    cin >> a >> b >> ref;

    vs guests;
    guests.pb(a); guests.pb(b);

    if(ref.size() != (a.size() + b.size()))
        cout << "NO";
    else {
        forn(i,2){
            intl n = guests[i].size();
            forn(j,n){
                forn(idx,ref.size()){
                    if((guests[i])[j] == ref[idx]){
                        ref[idx] = '1';
                        break;
                    }
                }
            }
        }

        forn(i,ref.size())
            if(ref[i] != '1'){
                cout << "NO";
                return 0;
            }

        cout << "YES";
    }

}