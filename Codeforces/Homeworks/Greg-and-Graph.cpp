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
#define err_dis(i, j) cout << "dis[" << i << "][" << j << "] = " << dis[i][j] << endl
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 5e2 + 100; 
const int INF = 1e9 + 7; 

ll dis[MAX][MAX]; 
int qu[MAX], mark[MAX];
vector<ll> ans;
int n; 

ll Solve(int v){
	ll sum = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dis[i][j] = min(dis[i][j], dis[i][v] + dis[v][j]);

			if(mark[i] && mark[j]) sum += dis[i][j];
		}
	}

	return sum;
}

main()
{IOS;

	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) cin >> dis[i][j];

	for(int i = 1; i <= n; i++) cin >> qu[i];

	for(int i = n; i >= 1; i--){
		mark[ qu[i] ] = 1;
		ans.pb( Solve( qu[i] ) );
	} 

	reverse(all(ans));
	for(ll u: ans) cout << u << ' ';

}