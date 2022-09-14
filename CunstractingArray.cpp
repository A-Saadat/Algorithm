#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i=k;i<n;i++) 
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
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 
#define spii set<pii>

spii a;

vci ans(def);

void Solve(ll n){
    ll idx = 1;
    
    a.insert(mp(-n, 1));
    while(a.size() > 0){
        pii tmp = *a.begin();

        ll R = -tmp.F + tmp.S - 1;
        ll L = tmp.S;

        getchar();
        if(L == R)
        {
            ans[L] = idx;
            idx++;
            a.erase(a.begin());
            continue;    
        }

        ll MID = 0;
        if(n % 2 != 0) MID = (R + L) / 2;
        else MID = (R + L - 1) / 2;

        ans[MID] = idx;
        ++idx;
        a.erase(a.begin());

        if(MID - L >= 1)
            a.insert(mp(L - MID, L));
        if(R - MID >= 1)
            a.insert(mp(MID - R, MID + 1));

    }

    forn(i,1,(n + 1)){
        if(!ans[i]) cout << ans[i];
    }
}

int main (void)
{
    ll n; cin >> n;
    forn(i,0,n){
        ll q;
        cin >> q;

        a.clear(); ans.clear();
        Solve(q);
    }
}