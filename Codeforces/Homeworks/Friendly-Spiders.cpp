// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define bp __builtin_popcount 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef map<string, int> msi;  
typedef map<char, int> mci; 
typedef map<int, int> mint; 
typedef set<int> si;  
typedef int64_t i64; 
typedef vector<int> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const int MaxN = 1e6; 
const ll INF = 1e9 + 7; 
const int lim = 3e5;
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int a[MaxN], mark[MaxN], par[MaxN], idx[MaxN];
bool isExist[MaxN], isChecked[MaxN];
vci adj[MaxN], Prime, tmp, ans; 
int n, s, t, maxi; 

void FindPrime(int n){
    bool isNotPrime[MaxN];

    for(int i = 2; i * i <= n; i++)
        for(int j = i * i; j <= n; j += i) isNotPrime[j] = true;
    
    forn(i,2,n) 
        if(!isNotPrime[i]) Prime.pb(i);
}

void draw_Graph(){
    for(int u: Prime){

        for(int i = u; i <= maxi + 100; i += u){

            if(isExist[i]){
                adj[u + lim].pb(i);
                adj[i].pb(u + lim);
            }

        }
    }
}

void bfs(int l, int r){
    queue<int> q; q.push(l);

    while(!q.empty()){
        int h = q.front(); mark[h] = 1;
        for(int u: adj[h]){
            if(!mark[u]){
                q.push(u); mark[u] = 1;
                par[u] = h;
            }
        }
        q.pop();
    }
}

main ()
{IOS;

    cin >> n;
    forn(i,0,n){
        cin >> a[i];
        // ? Save the index of Every number in array
        if(!isChecked[ a[i] ]){
            idx[ a[i] ] = i + 1;
            isChecked[ a[i] ] = 1;
        }
        isExist[ a[i] ] = 1;
        maxi = max(maxi, a[i]);
    }
    cin >> s >> t;

    // ** Special Testcases - Start
    if(s == t){
        cout << 1 << endl << s;
        return 0;
    }

    if(a[s - 1] == 1 || a[t - 1] == 1){
        cout << -1 << endl;
        return 0;
    }

    if(gcd(a[s - 1], a[t - 1]) > 1){
        cout << 2 << endl << s << ' ' << t;
        return 0;
    }
    // ** Special Testcases - end

    FindPrime(maxi + 1000);
    draw_Graph();
    bfs(a[-- s], a[-- t]);

    // ** IF we didn't visit T, so There is no path Between S and T
    if(!mark[ a[t] ]) {
        cout << -1 << endl;
        return 0;
    }

    // ? Saving the Path from "S" to "T"
    ans.pb(t + 1);
    int curr = par[a[t]]; bool isVal = true;
    while(curr != a[s]){
        ans.pb( idx[curr] );
        
        curr = par[curr];
    }
    ans.pb(++s);

    reverse( all(ans) );

    // ? Find the Size of Path
    int cnt = 0;
    for(int u: ans)
        if(u != 0) cnt++; 


    cout << cnt << endl;
    for(int u: ans)
        if(u != 0) cout << u << ' ';
}