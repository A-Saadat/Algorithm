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
typedef vector<int> vi;

const int MAX = 1e6 + 100; 
const int MaxN = 2e5 + 10;
const int INF = 1e9 + 7; 
const int sq = 500;

struct Query{ int L; int R; int idx; };

int cnt[MAX], a[MaxN];
long long int res[MaxN], ans;
vector<Query> v;

bool cmp(Query A, Query B){
    if(A.L / sq < B.L / sq) return 1;
    elif(A.L / sq == B.L / sq) return (A.R < B.R);
    else return 0;
}

inline void add(int curr){
    ans -= 1LL * cnt[ a[curr] ] * cnt[ a[curr] ] * a[curr];
    cnt[ a[curr] ]++;
    ans += 1LL * cnt[ a[curr] ] * cnt[ a[curr] ] * a[curr];
}

inline void remove(int curr){
    ans -= 1LL * cnt[ a[curr] ] * cnt[ a[curr] ] * a[curr];
    cnt[ a[curr] ]--;
    ans += 1LL * cnt[ a[curr] ] * cnt[ a[curr] ] * a[curr];
}

main()
{IOS;

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++){
        int l, r; cin >> l >> r;
        v.pb( {l, r, i} );
    }

    sort(all(v), cmp);

    int curr_L = 0, curr_R = -1;
    for(Query u: v){
        int L = u.L, R = u.R, idx = u.idx;

        while(curr_L > L){
            curr_L--;
            add(curr_L);
        }
        while(curr_R < R){
            curr_R++;
            add(curr_R);
        }
        while(curr_L < L){
            remove(curr_L);
            curr_L++;
        }
        while(curr_R > R){
            remove(curr_R);
            curr_R--;
        }

        res[idx] = ans;
    }

    for(int i = 1; i <= q; i++) cout << res[i] << endl;
}