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

int a[MAX]; 
ll ans;
int n; 

inline ll Solve(int id){
    int bs = (id * (id + 1) * (2 * id + 1)) / 6;
    for(int i = id + 1; )
}

main()
{IOS;  

    int t; cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        for(int i = 1; i < n; i++){
            ans = max(ans, Solve(i));
        }
    }

    

}