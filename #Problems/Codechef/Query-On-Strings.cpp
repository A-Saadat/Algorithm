#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define all(v) v.begin(), v.end() 
#define pb push_back 
#define elif else if 
#define S second 
#define F first 
#define int long long 

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

struct node{
    int num; int hig;
    bool operator< (const node& B) const{
        if(num != B.num) return (num < B.num);
        return (hig > B.hig);
    }
};

int dp[MAX], h[MAX];
map<pair<char, int>, int> mp; 
multiset<node> ms;
int cnt = 1;
string s; 

struct Trie{

    void erase(int u){
        auto it = ms.find({dp[u], h[u]});
        if(it == ms.end()) return;
        ms.erase(it);
    }

    void upd(int pnt, int v, int val){
        if(pnt == s.size()) return;
        if(!mp[{v, s[pnt]}]){
            cnt++;
            mp[{v, s[pnt]}] = cnt;
            h[cnt] = h[v] + 1;
        }
        int u = mp[{v, s[pnt]}];
        erase(u);
        dp[u] += val;
        ms.insert({dp[u], h[u]});

        upd(pnt + 1, u, val);
    }

} tri;

signed main()
{IOS;

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1 || t == 3){
            cin >> s;
            reverse(all(s));
            int val = (t == 1 ? +1 : -1);
            tri.upd(0, 1, val);
        }
        else{
            int k, l; cin >> k >> l;
            for(auto [num, hig]: ms) cout << "{" << num << ", " << hig << "}\n";
            cout << endl;
            auto it = ms.lower_bound({k, INF});
            if(it == ms.end()) cout << "*OUT\n";
            else cout << "*{" << it->num << ", " << it->hig << "}\n";
            if(it == ms.end() || it->hig < l) cout << "NO\n";
            else cout << "YES\n";
            cout << "\n----------------------\n";
        }
    }


}