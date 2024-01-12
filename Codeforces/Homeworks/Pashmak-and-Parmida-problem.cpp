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

const int MAX = 1e6 + 10; 
const int INF = 1e9 + 7; 

int pre[MAX], suf[MAX], all[MAX];
int n;

inline vector<int> merge( vector<int> A, vector<int> B ){
    int a = A.size(), b = B.size();
    int i = 0, j = 0;

    vector<int> ans;
    while(i < a && j < b){
        if(A[i] < B[j]) ans.pb(A[i]), i++;
        else ans.pb(B[j]), j++;
    }

    while(i < a) ans.pb(A[i]), i++;
    while(j < b) ans.pb(B[j]), j++;

    return ans;
}

vector<int> v[4 * MAX];
struct Segment{
    void build(int id, int l, int r){
        if(l + 1 == r){
            v[id].pb(all[l]);
            return;
        }

        int mid = (r + l) >> 1;
        build(2 * id + 0, l, mid); 
        build(2 * id + 1, mid, r);

        v[id] = merge(v[2 * id + 0], v[2 * id + 1]);
    }

    long long get(int id, int L, int R, int l, int r, int val){
        if(L == l && R == r){
            long long res = lower_bound(all(v[id]), val) - v[id].begin();
            return res;
        }

        int mid = (L + R) >> 1;
        long long ret1 = 0, ret2 = 0;
        if(l < mid)
            ret1 = get(2 * id + 0, L, mid, l, min(r, mid), val);
        if(r > mid)
            ret2 = get(2 * id + 1, mid, R, max(l, mid), r, val);

        return ret1 + ret2;
    }
};

Segment seg;

map<int, int> cnt;

main()
{IOS;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> all[i];

    for(int i = 0; i < n; i++){
        cnt[all[i]]++;
        pre[i + 1] = cnt[all[i]];
    }
    cnt.clear();
    for(int i = n - 1; i >= 0; i--){
        cnt[all[i]]++;
        suf[i + 1] = cnt[all[i]];
    }

    memset(all, 0, sizeof(all));
    for(int i = 1; i <= n; i++) all[i] = suf[i];

    seg.build(1, 1, n + 1);
    long long ans = 0;
    for(int i = 1; i < n; i++){
        int res = seg.get(1, 1, n + 1, i + 1, n + 1, pre[i]); 
        ans += res;
    }

    cout << ans << endl;
}