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
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector<int> a, b; 
map<int, int> mp[5];
int m; 

inline vector<int> fill_vectors(int h, int x, int y){
    vector<int> c;

    int curr = ( ((h * x) % m) + (y % m) ) % m;
    c.pb(h); c.pb(curr);

    while(curr != h){
        curr = ( ((curr * x) % m) + y ) % m;
        c.pb(curr);
    }

    c.pop_back();
    return c;
}

inline int find_id(vector<int> &c, int v){
    int ans = -1;
    int id = 0;

    for(int u: c){
        if(u == v){
            ans = id;
            break;
        }
        ++id;
    }

    return ans;
}

main()
{IOS;

    cin >> m;

    int h1, a1; cin >> h1 >> a1;
    int x1, y1; cin >> x1 >> y1;

    int h2, b1; cin >> h2 >> b1;
    int x2, y2; cin >> x2 >> y2;

    a = fill_vectors(h1, x1, y1);
    b = fill_vectors(h2, x2, y2);

    int id1 = find_id(a, a1);
    int id2 = find_id(b, b1);

    if(id1 == -1 || id2 == -1) cout << -1 << endl;
    elif(id1 == id2) cout << id1 << endl;
    else
        cout << (id1 * id2) / gcd(id1, id2) << endl; 
}