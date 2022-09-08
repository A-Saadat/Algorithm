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
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

double cu_sqrt(ll x){

    double R = x, L = -1;
    while(R - L > 1e-9){
        double MID = L + ((R - L) / 2);

        if(MID * MID > x) R = MID;
        else L = MID;
    }

    return L;
}

int main (void)
{
    ll n; cin >> n;
    cout << cu_sqrt(n);
}