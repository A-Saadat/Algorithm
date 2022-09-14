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

vector<vci> Subsequence(i64 x){
    vector<vci> sbq((1 << x));

    forn(mask,0,(1 << x)){
        forn(j,0,x){
            if((mask >> j) & 1 == 1) sbq[mask].pb(j + 1);
        }
    }   

    return sbq;
}

int main (void)
{
    ll x; cin >> x;

    vector<vci> sbq = Subsequence(x);

    forn(i,0,sbq.size()){
        cout << "{ ";

        forn(j,0,(sbq[i].size())){
            sbq[i].size() == 1 ? cout << sbq[i][j] : cout << sbq[i][j] << ", ";
        }
        cout << " }" << endl;
    }   
}