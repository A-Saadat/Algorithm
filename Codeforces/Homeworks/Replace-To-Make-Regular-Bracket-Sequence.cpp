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

int a[MaxN];
vector<int> v; 

main()
{IOS;

    string s; cin >> s;
    int n = s.size();
    forn(i,0,n){
        if(s[i] == '{' || s[i] == '}') a[i] = 1;
        elif(s[i] == '[' || s[i] == ']') a[i] = 2;
        elif(s[i] == '<' || s[i] == '>') a[i] = 3;
        else a[i] = 4;
    }

    int op = 0, cl = 0;
    forn(i,0,n) {
        if(s[i] == '{' || s[i] == '<' || s[i] == '[' || s[i] == '(') op++;
        else cl++;
    }

    if(cl != op){
        cout << "Impossible";
        return 0;
    } 

    int cnt = 0;
    forn(i,0,n){
        if(s[i] == '{' || s[i] == '<' || s[i] == '[' || s[i] == '(') v.pb(i);
        else{

            if(v.empty()) {
                cout << "Impossible";
                return 0; 
            }

            int id = v.back();
            if(a[i] != a[id]) cnt++;// cout << i << ": " << id << " -> " << s[i] << ' ' << s[id] << endl;
            v.pop_back();
        }
    }

    cout << cnt;

}