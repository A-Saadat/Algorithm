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
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const int MaxN = 2600 + 100; 
const int MAX = 5e4;
const int INF = 1e9 + 7; 

int dp[MaxN][MaxN];
char c[MAX], ans[MAX];
int n;
map<char, int> mp;

inline void input(){
    string s; cin >> s; 
    n = s.size();
    for(int i = 0; i < n; i++) c[i + 1] = s[i], mp[ s[i] ]++;
}

inline void Update_dp(){
    for(int k = 0; k < 2; k++){ // ? Base of the dp
        for(int l = 1; l + k <= n; l++){
            int r = l + k;
            if(l == r) dp[l][r] = 1;
            else dp[l][r] = 1 + (c[l] == c[r]);
        }
    }

    for(int k = 2; k < n; k++){
        for(int l = 1; l + k <= n; l++){
            int r = l + k;

            dp[l][r] = max(dp[l + 1][r - 1] + (c[l] == c[r] ? 2 : 0), max(dp[l + 1][r], dp[l][r - 1]));
        }
    }
}

int id = 0;
void BT(int l, int r){
    if(l > r) return;
    if(l == r) ans[++id] = c[l];
    elif(c[l] == c[r]){
        ans[++id] = c[l];
        BT(l + 1, r - 1);
        ans[++id] = c[r];
    }
    else{
        if(dp[l + 1][r] > dp[l][r - 1]) BT(l + 1, r);
        else BT(l, r - 1);
    }
}

main()
{IOS;

    input();
    if(n >= 2600) {
        for(int i = 'a'; i <= 'z'; i++) {
            if(mp[ (char) i ] >= 100) {
                int z = 100;
                while(z--) cout << (char) i;
                break;
            }
        }  
    }
    else{
        Update_dp();
        BT(1, n);
        if(id <= 100) 
            for(int i = 1; i <= id; i++) cout << ans[i];
        else{
            for(int i = 1; i <= 50; i++) cout << ans[i];
            for(int i = 50; i >= 1; i--) cout << ans[i];
        }
    }
}