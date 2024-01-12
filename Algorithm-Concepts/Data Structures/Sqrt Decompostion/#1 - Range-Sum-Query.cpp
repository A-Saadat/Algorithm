#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define int long long 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX];
int dp[MAX]; // ? dp[i] = sum of elemnt from xk to x(k + 1)
int n, sum;
int sq;

inline int _get(int l, int r){
    int sum = 0;

    if((l / sq) == (r / sq)){
        for(int i = l; i <= r; i++) sum += a[i];
        return sum;
    }

    while(l % sq){
        sum += a[l];
        l++;
    }

    while((l / sq) != (r / sq)){ // ? until they meet in the same block
        sum += dp[(l / sq) + 1];
        l += sq;
    }

    for(int i = l; i <= r; i++) sum += a[i];
    return sum;
}

inline void _set(int l, int val){
    int grp = (l / sq) + 1;
    dp[grp] -= a[l];
    a[l] = val;
    dp[grp] += val;
}

main()
{IOS;

    cin >> n;
    sq = sqrt(n + .0);
    
    for(int i = 1; i <= n; i++){
        cin >> a[i]; 
        if(!(i % sq)){
            dp[i / sq] = sum; 
            sum = 0;
        }
        sum += a[i];
    }
    
    int q; cin >> q;
    while(q--){
        int type; cin >> type;

        if(type == 1) {
            int l, val; cin >> l >> val;
            _set(l, val);
        }
        else{
            int l, r; cin >> l >> r;
            cout << _get(l, r) << endl;
        }
    }
}