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

ll Binary_to_int(vci s){
    ll n = s.size();
    ll ans = 0;
    reverse(s.begin(), s.end()--);
    forn(i,0,n)
        if(s[i] == 1) ans += pow(2, i);

    return ans;
}

vci shayan, mansor;

vci Binary_String_Lenght(ll n){
    if(n == 0){
        forn(i,0,7) a.pb(1);
        shayan.pb(Binary_to_int(a));
        forn(i,0,7) a.pop_back();
    }
    else{
        a.pb(1);
        Binary_String_Lenght(n - 1);
        a.pop_back();

        a.pb(0);
        Binary_String_Lenght(n - 1);
        a.pop_back();
    }

    return;
}

int main (void)
{IOS;
    ll n; cin >> n;

    Binary_String_Lenght(n);
    forn(i,0,100) cout << shayan[i] << ' ';
    cout << endl;
}