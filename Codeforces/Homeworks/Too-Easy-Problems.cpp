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

const int MaxN = 1e6; 
const int INF = 1e9 + 7; 

pair<int, pair<int, int>> a[MaxN]; // ? a[i].F = Needed time for the i-th Problem, a[i].S.S = real index of the i-th problem 
vector<int> ans[MaxN];
int n, t, tmp; 

bool check(int mid){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i].F <= tmp && a[i].S.F >= mid){
            tmp -= a[i].F;
            ans[mid].pb( a[i].S.S );
            cnt++;
        }

        if(cnt == mid) break;
    }

    if(cnt < mid) return 0;
    else return 1;
}
 
main()
{IOS;

    cin >> n >> t;
    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        a[i] = {y, {x, i}};
    }

    sort(a + 1, a + n + 1);

    int L = 0, R = INF;
    while(R - L > 1){
        int mid = (R + L) / 2;

        if(check(mid)) L = mid;
        else R = mid;

        tmp = t;
    }

    cout << L << endl;
    cout << ans[L].size() << endl;
    for(int u: ans[L]) cout << u << ' ';
}