// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 

vi a; 
int mark[MaxN];
bool isOk;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        isOk = 1;
        a.clear();
        int n; cin >> n;
        string s; cin >> s;

        forn(i,0,n) {
            if(s[i] == 'M' || s[i] == 'm') a.pb(1), mark[1] = 1;
            elif(s[i] == 'E' || s[i] == 'e') a.pb(2), mark[2] = 1;
            elif(s[i] == 'O' || s[i] == 'o') a.pb(3), mark[3] = 1;
            elif(s[i] == 'W' || s[i] == 'w') a.pb(4), mark[4] = 1;
            else isOk = false;
        }

        forn(i,0,n - 1) 
            if(a[i] > a[i + 1]) isOk = false;

        if(a[0] != 1 || a[n - 1] != 4) isOk = false;
        if(!mark[1] || !mark[2] || !mark[3] || !mark[4]) isOk = false;

        if(isOk) cout << "YES" << endl;
        else cout << "NO" << endl;

        a.clear();
        memset(mark, 0, sizeof(mark));

    }

}