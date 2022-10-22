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

vpii a;

int main (void)
{
    ios_base::sync_with_stdio(false);

    ll t; cin >> t;
    while(t--){
        ll n, H, M; cin >> n >> H >> M;
        forn(i,0,n){
            ll h, m; cin >> h >> m;
            a.pb(mp(h, m));
        }

        sort(a.begin(), a.end());
        ll h = a[0].F, m = a[0].S;

        if(H > h){
            ll Hours = 24 - H, Min = 0;
            if(M > 0){
                --Hours;
                Min = 60 - M;
            }
            Hours += h;
            Min += m;
            if(Min >= 60){
                Min %= 60;
                ++Hours;
            }

            cout << Hours << ' ' << Min << endl;
        }
        elif(H < h){
            ll Hours = H - h, Min = 0;
            if(M > 0 and m == 0){
                --Hours;
                Min = 60 - M;
            }
            elif(M == 0 and m > 0){
                --Hours;
                Min = m;
            }
            
            cout << Hours << ' ' << Min << endl;
        }
        elif(H == h){

        }
    }

}