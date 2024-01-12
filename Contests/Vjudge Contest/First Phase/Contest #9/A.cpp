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
struct que{
    int l; int r; char c;
}; 

vector<que> q;
vector<char> v;
int n, k; 
vector<char> ans; 
int mini = INF;

void BT(int id){
    if(id == n + 1){
        bool en = 1;
        for(auto u: q){
            int l = u.l, r = u.r; char c = u.c;
            bool isOk = 0;
            for(int i = l; i <= r; i++){
                if(v[i - 1] == c) isOk = 1;
            }

            if(!isOk) {en = 0; break;}
        }

        int cnt = 0;
        for(char u: v){
            if(u != '.') cnt++;
        }

        if(en){
            for(char u: v) cout << u << ' ';
            cout << "\n-------------\n";
        }

        if(mini >= cnt && en){
            ans.clear();
            for(char u: v) ans.pb(u);
            mini = cnt;
        }
        return;
    }

    v.pb('H');
    BT(id + 1);
    v.pop_back();
    v.pb('G');
    BT(id + 1);
    v.pop_back();
    v.pb('.');
    BT(id + 1);
    v.pop_back();
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        q.clear(); ans.clear(); v.clear();
        cin >> n >> k;
        string s; cin >> s;
        for(int i = 0; i < s.size(); i++){
            int l = max(1LL * 1, i + 1 - k);
            int r = min(n, i + 1 + k);
            char c = s[i];
            q.pb({l, r, c});
        }

        BT(1);

        cout << mini << endl;
        for(char u: ans) cout << u;
        cout << endl;
    }

}