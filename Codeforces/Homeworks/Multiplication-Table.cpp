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

ll a[100][100];

const ll LIMIT = pow((5 * 1e5), 2) + 1;

int main (void)
{
    ll n, m, k; cin >> n >> m >> k;

    if(n == 1 or m == 1){
        cout << k;
        return 0;
    }

    ll L = -1, R = LIMIT;
    while(R - L > 1){
        ll MID = (R + L) / 2;

        ll sum = 0;
        forn(i,1,(n + 1)){
            sum += min(((MID - 1) / i), m);
        }

        if(sum >= k) R = MID;
        elif(sum < k) L = MID;
    }

    cout << L;
}