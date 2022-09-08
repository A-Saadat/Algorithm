#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define msi map<string, int> 
#define mci map<char, int> 
#define si set<int> 
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

intl evenCnt, oddCnt;
intl a[def];

int main (void)
{
    intl n; cin >> n;
    forn(i,n){
        cin >> a[i];
        a[i] % 2 != 0 ? oddCnt++ : evenCnt++;
    }

    bool isEven = false;
    if(evenCnt > oddCnt) isEven = true;

    forn(i,n){
        if(isEven){
            if(a[i] % 2 != 0){
                cout << i + 1 << endl;
                return 0;
            }
        }
        else{
            if(a[i] % 2 == 0){
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
}   