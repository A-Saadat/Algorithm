#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

// ? We can See that if we pick k elements, then our total joy will equal to
// ? a[i1] - d * (i1) + a[i2] - d * (i2 - i1) + .... + a[ik] - d * (ik - ik-1) 
// ? = a[i1] + a[i2] + ... + a[ik] - d * ik
// ? sum + (a[ik] - d * k)
// ? which sum is equal to the maximum sum of m - 1 elements on the prefix [1, ik - 1] 

ll a[MAX]; 
multiset<ll> s;
ll n, m, d; 

inline ll Solve(){
    ll ans = 0, sum = 0;
    for(int i = 1; i <= n; i++){
        
        ll curr = sum + (a[i] - (d * i) ); // ? GO UP
        ans = max(ans, curr);

        if(a[i] > 0){
            s.insert(a[i]);
            sum += a[i];
            if(s.size() >= m) {
                auto itr = s.begin();
                sum -= *itr;
                s.erase(itr);
            }
        }
    }

    return ans;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n >> m >> d;
        for(int i = 1; i <= n; i++) cin >> a[i];

        s.clear();
        cout << Solve() << endl;
    }

}