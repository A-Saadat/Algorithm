// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false) 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define elif else if 
typedef long long int ll; 
typedef map<string, int> msi;  
typedef map<char, int> mci; 
typedef map<ll, ll> mll; 
typedef set<int> si;  
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll def = 1e6; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vci a;

int main (void)
{IOS;

    string s; cin >> s;
    ll n = s.size();

    ll ans = def;   
    forn(i,0,26){
        a.clear();
        char c = (char) i + 97;
        
        forn(i,0,n)
            if(s[i] == c) a.pb(i + 1);

        if(a.size() == 0) continue;

        ll maxLenght = a[0];
        forn(i,1,a.size()) maxLenght = max(maxLenght, a[i] - a[i - 1]);
        maxLenght = max(maxLenght, n - a[a.size() - 1] + 1);
        
        // cout << c << " : MAX -> " << maxLenght << endl;
        ans = min(ans, maxLenght);
    }

    cout << ans;

}