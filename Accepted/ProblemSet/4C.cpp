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
typedef long long int ll; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

msi a;
vs str;

int main (void)
{
    ll n; cin >> n;
    forn(i,n){
        string x; cin >> x;
        str.pb(x);

        if(a.find(x) == a.end()) a.insert(mp(x,0));

        if(a[str[i]] == 0) cout << "OK" << endl;
        else cout << str[i] << (a[str[i]]) << endl;

        a[x]++;
    }
}