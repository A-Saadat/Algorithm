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

ll toInt(string s){
    ll idx = 0, ans = 0;
    while(idx < s.size()){
        ans += (s[idx] - '0') * pow(10, s.size() - 1 - idx);
        idx++;
    }

    return ans;
}

ll to_int(string s, ll len, ll ans){
    if(len < 0) return 0;

    ans = (s[len] - '0') * pow(10, (s.size() - 1 - len)) + to_int(s, --len, ans);
    return ans;
}

int main (void)
{
    string s; cin >> s;

    cout << to_int(s, s.size() - 1, 0);
}