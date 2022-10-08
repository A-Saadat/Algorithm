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

vpii v;

int main (void)
{
    ios_base::sync_with_stdio(false);

    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll l1 = abs(x1 - x2);
    ll l2 = abs(y1 - y2);

    ll lenght = 0;
    if(l1 == l2 || (l1 == 0 && l2 > 0) || (l2 == 0 && l1 > 0)){
        if(l1 > 0) lenght = l1;
        elif(l2 > 0) lenght = l2;
        pii a = mp(x1, y1), b = mp(x2, y2);
        v.pb(a); v.pb(b); sort(v.begin(), v.end());

        if(abs(x1 - x2) > 0 && abs(y1 - y2) > 0){ // ? diagonal
            cout << v[0].F + lenght << ' ' << v[0].S << ' ';
            cout << v[1].F - lenght << ' ' << v[1].S << endl;
        }
        elif(abs(x1 - x2) == 0 && abs(y1 - y2) > 0) { // ? Vertical
            cout << v[0].F + lenght << ' ' << v[0].S << ' ';
            cout << v[1].F + lenght << ' ' << v[1].S << ' ';
        }
        elif(abs(x1 - x2) > 0 && abs(y1 - y2) == 0) { // ? Horizantal
            cout << v[0].F << ' ' << v[0].S + lenght << ' ';
            cout << v[1].F << ' ' << v[1].S + lenght << ' ';
        }
    }
    else cout << "-1" << endl;

}