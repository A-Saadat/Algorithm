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

const ll LIMIT = 1.5 * 1e5; 
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[def];
ll sum[def];

int main (void)
{
    ios_base::sync_with_stdio(false);

    ll t; cin >> t;
    while(t--){
        ll n, q; cin >> n >> q;
        forn(i,0,n) cin >> a[i]; sort(a, a + n); // ? store the Input and sort the array
        forn(i,0,n) sum[i] += sum[i - 1] + a[i]; // ? prefix Sum

        forn(i,0,q){ // ? handle Queries
            ll q; cin >> q;
            
            ll L = -1, R = LIMIT;
            while(R - L > 1){ // ? Binary Search
                ll MID = (R + L) / 2;

                ll maxSum = 0;
                forn(i,0,n){
                    ll x = 0;
                    i - MID > 0 ? x = sum[i] - sum[i - MID] : x = sum[i]; // ! handle the prefix sum to determine the candies set
                    maxSum = max(maxSum, x);
                }

                if(maxSum >= q) R = MID;
                elif(maxSum < q) L = MID; 
            }
            if(R > n) cout << "ans -> " << -1 << endl;
            else cout << "ans -> " << (R == 0 ? R + 1 : R) << endl;
        }
    }
}

// 1
// 8 1
// 4 3 3 1 1 4 5 9
// 50