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

ll a[def];
ll sum[def];

int main (void)
{
    ll n; cin >> n;
    forn(i,0,n) cin >> a[i];

    forn(i,0,n) sum[i] = sum[i - 1] + a[i];

    ll max = 0, min = a[0];
    forn(i,0,n){
        if(sum[i] > max) max = sum[i]; 
        elif(sum[i] < min) min = sum[i];
    }

    cout << max - min << endl;
}