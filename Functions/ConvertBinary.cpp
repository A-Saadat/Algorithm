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

string Binary(int x) {
    string t;
    while(x > 0){
        if(x % 2 == 0)
            t += "0";
        else
            t += "1";

        x /= 2;
    }

    ll size = t.size();

    string ans;
    for(ll i = size; i >= 0; i--)
        ans += t[i];

    return ans;
}

ll Binary_to_int(vci s){
    ll n = s.size();
    ll ans = 0;
    reverse(s.begin(), s.end()--);
    forn(i,0,n)
        if(s[i] == 1) ans += pow(2, i);

    return ans;
}


int main (void)
{IOS;

    cout << Binary_to_int(a);

}