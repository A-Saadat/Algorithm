#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define all(v) v.begin(), v.end() 
#define pb push_back 
#define elif else if 
#define S second 
#define F first 

const int MAX = 1e6 + 10; 
const int INF = 1e9 + 7; 

string s[MAX]; 
map<pair<int, char>, int> mp;
set<int> s1[MAX], s2[MAX];
int cnt = 1;
string str;

struct Trie{

    void build(int i, int v, int pnt){
        s2[v].insert(i);
        if(pnt == s[i].size()) {s1[v].insert(i); return;}
        
        if(!mp[{v, s[i][pnt]}])
            mp[{v, s[i][pnt]}] = ++cnt;

        int u = mp[{v, s[i][pnt]}];
        build(i, u, pnt + 1);
    }

    void erase(int i, int v, int pnt){
        s2[v].erase(i);
        if(pnt == s[i].size()) {s1[v].erase(i); return;}

        int u = mp[{v, s[i][pnt]}];
        erase(i, u, pnt + 1);
    }

    bool isOk = 0;
    bool get_vpre(int l, int r, int v, int pnt){
        if(pnt == str.size() || !mp[{v, str[pnt]}]){
            auto ret = (s1[v].lower_bound(l));
            if(ret != s1[v].end() && *ret <= r) isOk |= 1;
            return isOk;
        } 

        int u = mp[{v, str[pnt]}];
        auto ret = (s1[v].lower_bound(l));
        if(ret != s1[v].end() && *ret <= r) return 1;
        else return get_vpre(l, r, u, pnt + 1);
    }

    bool get_spre(int l, int r, int v, int pnt){
        if(pnt == str.size()){
            auto ret = (s2[v].lower_bound(l));
            if(ret != s2[v].end() && *ret <= r) return 1;
            return 0;
        }

        int u = mp[{v, str[pnt]}];
        if(!u) return 0;
        return get_spre(l, r, u, pnt + 1);
    }


} tri;  

signed main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i], tri.build(i, 1, 0);    

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int i; cin >> i >> str;
            tri.erase(i, 1, 0);
            s[i] = str;
            tri.build(i, 1, 0);
        }
        elif(t == 2){
            tri.isOk = 0;
            int l, r; cin >> l >> r >> str;
            cout << (tri.get_vpre(l, r, 1, 0) ? "Y\n" : "N\n");
        }
        else{
            int l, r; cin >> l >> r >> str;
            cout << (tri.get_spre(l, r, 1, 0) ? "Y\n" : "N\n");
        }
    }
}
