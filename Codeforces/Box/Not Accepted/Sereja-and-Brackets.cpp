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
int n;

struct nod{
    int cl, op, tot;
    nod(){
        cl = 0;
        op = 0;
        tot = 0;
    }
} p[(MAX << 4)];

struct Segment{

    void build(int id = 1, int l = 1, int r = n + 1){
        if(l + 1 == r){
            if(a[l] == 0) p[id].cl = 1;
            else p[id].op = 1;
            p[id].tot = 0; 
            return;
        }
        
        int mid = (l + r) >> 1, lc = id << 1, rc = lc | 1;
        build(lc, l, mid);
        build(rc, mid, r);

        p[id].op = p[lc].op + p[rc].op;
        p[id].cl = p[lc].cl + p[rc].cl;
        p[id].tot = p[lc].tot + p[rc].tot + (p[lc].op - (p[lc].tot / 2)) + (p[rc].cl - (p[rc].tot / 2));

        cout << id << " -> [" << l << ", " << r << "]\n" << "|| total = " << p[id].tot << "|| close = " << p[id].cl << "|| open = " << p[id].op << endl;
        cout << "\n------------------\n";
    }

} seg;

main()
{IOS;

    string s; cin >> s; n = s.size();
    for(int i = 0; i < n; i++) a[i + 1] = (s[i] == ')' ? 0 : 1);
    seg.build();

}