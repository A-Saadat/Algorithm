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

const int MAX = 1e6 + 10; 
const int INF = 1e9 + 7; 

int ans;

struct r{ int x; int y; int a; };
bool cmp(r A, r B) { return (A.x < B.x ? 1 : 0); }
struct line{
    int a; int b; // ? a = slope
    int eval(int x) { return a * x + b; }
    double intersectX(line L) { return (L.b - b) / (a - L.a); }
};

vector<r> rect;

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y, a; cin >> x >> y >> a;
        rect.pb({x, y, a});
    }

    sort(all(rect), cmp);
    deque<line> dq;
    dq.push_front({0, 0});
    
    for(int i = 0; i < n; i++){
        int x = rect[i].x, y = rect[i].y, a = rect[i].a;
        while(dq.size() >= 2 && dq.back().eval(y) <= dq[dq.size() - 2].eval(y))
            dq.pop_back();
        
        int new_line = dq.back().eval(y) + x * y - a;
        line curr = {-x, new_line};
        ans = max(ans, new_line);

        while(dq.size() >= 2 && curr.intersectX(dq[0]) >= dq[0].intersectX(dq[1]))
            dq.pop_front();
        
        dq.push_front(curr);
    }

    cout << ans << endl;
}