#include <bits/stdc++.h> 
using namespace std; 

#define def 1001
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

ll board[def][def];
ll sum[def][def];


int main (void)
{
    ll t; cin >> t;

    while(t--){
        forn(i,1,1001){
            forn(j,1,1001){
                sum[i][j] = 0; board[i][j] = 0;
            }
        }

        ll n, q; cin >> n >> q;
        forn(i,0,n){
            ll x, y; cin >> x >> y;
            board[x][y] += x * y;
        }
        
        forn(i,1,1001){
            forn(j,1,1001){
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + board[i][j];
            }
        }

        ll ans = 0;
        forn(i,0,q){
            ll hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb;

            ans = sum[hb - 1][wb - 1] - sum[hs][wb - 1] - sum[hb - 1][ws] + sum[hs][ws];

            cout << ans << endl;
        }
    }
}

