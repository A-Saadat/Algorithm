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
// #define int long long 

const int MAX = 1e6; 
const int INF = 1e9 + 7; 
int a, b, xk, yk, xq, yq;



bool check(int x, int y){
    int cnt = 0;
    if(x - a == xq && y - b == yq) cnt++;
    if(x - a == xq && y + b == yq) cnt++;
    if(x + a == xq && y - b == yq) cnt++;
    if(x + a == xq && y + b == yq) cnt++;

    if(x - b == xq && y - a == yq) cnt++;
    if(x - b == xq && y + a == yq) cnt++;
    if(x + b == xq && y - a == yq) cnt++;
    if(x + b == xq && y + a == yq) cnt++;

    return (cnt > 0);
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        set<pair<int, int>> s;
 
        cin >> a >> b >> xk >> yk >> xq >> yq;

        int cnt = 0;

        int x = xk - a;
        int y = yk - b;
        if(check(x, y)) s.insert({x, y});

        x = xk + a;
        y = yk - b;
        if(check(x, y)) s.insert({x, y});

        x = xk - a;
        y = yk + b;
        if(check(x, y)) s.insert({x, y});

        x = xk + a;
        y = yk + b;
        if(check(x, y)) s.insert({x, y});


        x = xk - b;
        y = yk - a;
        if(check(x, y)) s.insert({x, y});

        x = xk + b;
        y = yk - a;
        if(check(x, y)) s.insert({x, y});

        x = xk - b;
        y = yk + a;
        if(check(x, y)) s.insert({x, y});

        x = xk + b;
        y = yk + a;
        if(check(x, y)) s.insert({x, y});

        cout <<  s.size() << endl;
    }

}