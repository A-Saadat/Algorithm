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
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const int MaxN = 1e6; 
const int INF = 1e9 + 7; 

int a[MaxN]; 
vi odd;
int n; 
bool isOk;

ll search(int x){
    int L = 0, R = odd.size() + 1;
    while(R - L > 1){
        int mid = (R + L) / 2;

        if(odd[mid] < x) L = mid;
        else R = mid;
    }

    return (odd[L] < x);
}

void clear(){
    isOk = 1;
    odd.clear();
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        clear();

        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] % 2) odd.pb(a[i]);
        }

        sort( all(odd) );

        if(odd.size())
            for(int i = 1; i <= n; i++){
                if(!(a[i] % 2)) isOk = search(a[i]);
                if(!isOk) break;
            }
        
        if(isOk) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}