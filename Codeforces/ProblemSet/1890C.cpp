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

inline void Solve(){
    deque<char> q;
    vector<int> op;
    int n; cin >> n;
    string s; cin >> s;
    int c0 = 0, c1 = 0;
    for(char u: s){
        if(u == '0') c0++;
        else c1++;

        q.push_back(u);
    }

    if(c1 != c0) { cout << "-1\n"; return; }

    int d = 0;
    while(!q.empty()){
        int c = 0;
        if(q.front() != q.back()) q.pop_front(), q.pop_back();
        else{
            if(q.back() == '1'){
                q.pop_back();
                q.push_front('1');
                op.pb(d);
            }
            else{
                q.pop_front();
                q.push_back('0');
                op.pb(n - d);
            }
            n += 2;
        }

        d++;
    }

    cout << op.size() << endl;
    for(int u: op) cout << u << ' ';
    cout << endl;
}

main()
{IOS;

    int t; cin >> t;
    while(t--) Solve();

}