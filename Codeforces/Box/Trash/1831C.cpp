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
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

set< pair<int, pair<int, int> > > s;
vector< pair<int, pair<int, int> > > er_qu; 
int mark[MAX];

main()
{IOS;

    int t; cin >> t;
    while(t--){
        memset(mark, 0, sizeof(mark));
        int n; cin >> n;
        for(int i = 1; i < n; i++){
            int x, y; cin >> x >> y;
            s.insert( {i, {x, y}} );
        }

        mark[1] = 1; int cnt = 0;
        while(!s.empty()){
            ++cnt;
            fort(itr, s) {
                int id = itr->F;
                int v = itr->S.F;
                int u = itr->S.S;

                if(mark[u] || mark[v]){
                    mark[u] = 1;
                    mark[v] = 1;
                    er_qu.pb( {id, {v, u}} );
                }
            }

            for(auto u: er_qu)
                s.erase({u.F, {u.S.F, u.S.S}});

            er_qu.clear();
        }

        cout << cnt << endl;

    }

}