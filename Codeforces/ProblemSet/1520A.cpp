#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define forb(i,n,k) for(int i = (n - 1); i < k; i--) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define msi map<string, int> 
#define mci map<char, int> 
#define mll map<ll, ll> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
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

const ll LIMIT = 1e8; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char a[def], b[def];
bool ARE_YOU_DISTRACTED[def];

int main (void)
{
    ios_base::sync_with_stdio(false);

    ll t; cin >> t;
    while(t--){
        bool isOK = true;
        ll n; cin >> n;
        forn(i,0,n) cin >> a[i];
        forn(i,0,1000) ARE_YOU_DISTRACTED[i] = false;

        forn(i,0,n){
            if(!ARE_YOU_DISTRACTED[a[i] - 0]) ARE_YOU_DISTRACTED[a[i] - 0] = true;
            elif(ARE_YOU_DISTRACTED[a[i] - 0] and a[i - 1] != a[i]) isOK = false;
        }

        if(isOK) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
}