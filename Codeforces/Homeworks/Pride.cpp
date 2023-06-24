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

const int MaxN = 1e6; 
const int INF = 1e9 + 7; 

int a[MaxN]; 
bool isOk = false;
int L = MaxN, R = INF, cnt1 = 0;

main()
{IOS

    int n; cin >> n;
    forn(i,1,n + 1){
        cin >> a[i];
        if(a[i] == 1) cnt1++;
    } 

    if(cnt1) { cout << n - cnt1 << endl; return 0; }

    for(int l = 1; l <= n; l++){

        int G = a[l];
        forn(r, l, n + 1){
            G = gcd(G, a[r]);

            if(G == 1){
                isOk = true;
                if( (r - l) < (R - L) ) L = l, R = r;
            }

        }

    }

    cout << (isOk ? (R - L + n - 1) : -1);
}