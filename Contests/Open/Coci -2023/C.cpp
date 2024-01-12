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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX]; 
int n, q; 
vector<int> Av;
int mark[MAX];

void remove_poeple(int x){
    vector<int> tmp;
    while(x--){
        tmp.pb(Av.back());
        Av.pop_back();
    }
    Av.pop_back();
    reverse(all(tmp));
    for(int u: tmp) Av.pb(u);
}

int find_ans(){
    vector<int> v;
    for(int u: Av) v.pb(u);

    int ans = 0;
    vector<int> tmp;
    for(int i = 1; i <= n; i++){
        if(mark[i]) continue;
        tmp.clear();
        
        int idx = 0;
        for(int j = v.size() - 1; v[j] != i; j--) idx++;
        ans += idx + 1;

        while(idx--){
            tmp.pb(v.back());
            v.pop_back();
        }
        v.pop_back();

        sort(tmp.rbegin(), tmp.rend());

        for(int u: tmp) v.pb(u);
    }

    return ans;
}

main()
{IOS;

    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i], Av.pb(a[i]);
    reverse(all(Av));
    // for(int u: Av) cout << u << ' ';
    // cout << endl;
    cout << find_ans() << " ";
    while(q--){
        int x; cin >> x; mark[Av[Av.size() - x]] = 1; //cout << x << ": " << Av[Av.size() - x] << endl;
        remove_poeple(x - 1);   
        // for(int u: Av) cout << u << ' ';
        // cout << endl;
        cout << find_ans() << ' ';
    }

}