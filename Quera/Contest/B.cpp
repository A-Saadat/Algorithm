// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define scan(a, n) for(int i = 0; i < n; i++) cin >> a[i]; 
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

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[MaxN], sum[MaxN]; 
ll odd[MaxN], even[MaxN];

int main ()
{IOS;

    ll n; cin >> n;
    forn(i,1,n + 1) cin >> a[i];

    forn(i, 1, n + 1) sum[i] = sum[i - 1] + a[i];
    forn(i,1, n + 1){
        if(i % 2 == 0){
            even[i] = even[i - 1] + a[i];
            odd[i] = odd[i - 1];
        }
        else{
            odd[i] = odd[i - 1] + a[i];
            even[i] = even[i - 1];
        }
    }   

    ll t; cin >> t;
    while(t--){
        ll L, R; cin >> L >> R;

        ll ans = 0;
        if(L % 2 == 1) ans = (sum[R] - sum[L - 1]) - ((even[R] - even[L - 1]) * 2);
        else ans = (sum[R] - sum[L - 1]) - ((odd[R] - odd[L - 1]) * 2);

        cout << ans << endl;
    }
}