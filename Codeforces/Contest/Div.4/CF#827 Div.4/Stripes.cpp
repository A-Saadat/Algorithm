#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false) 
#define msi map<string, int> 
#define mci map<char, int> 
#define mll map<ll, ll> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define elif else if 
typedef long long int ll; 
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll LIMIT = 1e4; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char a[9][9];

int main (void)
{IOS;

    ll t; cin >> t;
    while(t--){
        forn(i,0,8){
            forn(j,0,8){
                cin >> a[i][j];
            }
        }

        bool isCompelete = false;
        forn(i,0,8){
            bool isOk = true;
            forn(j,0,8)
                if(a[i][j] != 'R') isOk = false;

            if(isOk == true) isCompelete = true;
        }

        if(isCompelete) cout << "R" << endl;
        else cout << "B" << endl;

    }

}