// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 1e3 + 100; 
const ll INF = 1e9 + 7; 

int dp[MaxN][MaxN]; 
char a[MaxN];
int n, k;

int dfs(int v, int u){
    if(n == v && (u == k || u == -k)) return 1;
    elif(n == v && (u > k || u < -k)) return 0;

    if(a[v] == 'W'){
        return dfs(v + 1, u + 1);

        
    }   
    elif(a[v] == 'D') return dfs(v + 1, u);
    elif(a[v] == 'L') return dfs(v + 1, u - 1);


}

main()
{IOS;

    cin >> n >> k;
    forn(i,1,n + 1) cin >> a[i];

    if(!dfs(0, 0)) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        forn(i,1,n + 1) cout << a[i];
    } 


}