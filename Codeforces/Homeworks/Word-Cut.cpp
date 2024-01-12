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
const int MOD = 1e9 + 7; 

int a[MAX]; 
int dp[2][1005]; 
vector<int> tp;

string str, fin;
int k, n, h;

inline void Find_Turning_Point(){
    int n = str.size();
	for (int i = 1; i <= n; ++i) {
		bool isOk = true;
		for (int j = i; j < i + n - 1; j++)
			if(str[j % n] != fin[j - i]) isOk = false;

		if(isOk) tp.pb(i);
	}
}

inline void Update_dp(){
    h = 1; int sum = 0, ns = 0;
	for (int i = 1; i < n; ++i) dp[1][i] = 1, sum += dp[1][i];

	while(--k){
		for (int i = 1; i <= n; ++i){
			dp[1 - h][i] = (sum - dp[h][i] + MOD) % MOD;
			ns += dp[1 - h][i];
			ns %= MOD;
		}

		sum = ns;
		ns = 0;
		h = 1 - h;
	}
}

inline int Solve(){
    Find_Turning_Point();
    Update_dp();

    int ans = 0;
	for(int u: tp) {
		ans += dp[h][u];
		ans %= MOD;
	}

	cout << ans;
}

main()
{IOS;
	cin >> str >> fin; cin >> k;
    n = str.size();

	if(k == 0){
		if(str == fin) cout << 1;
		else cout << 0;

		return 0;
	}

	Solve();
}