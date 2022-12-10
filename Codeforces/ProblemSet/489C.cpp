// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false) 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define elif else if 
typedef long long int ll; 
typedef map<string, int> msi;  
typedef map<char, int> mci; 
typedef map<ll, ll> mll; 
typedef set<int> si;  
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll def = 1e6; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[def], b[def]; 
ll n, s;
bool isOk(ll s, ll sum){
    if(sum == s) return 1;
    else return 0;
}



main ()
{IOS;

    cin >> n >> s;
    
    if((s == 0 && n > 1) || s > (n * 9)) { cout << "-1 -1" << endl; return 0; } 
    elif(s == 0 && n == 1) { cout << "0 0" << endl; return 0;}

    forn(i,0,n) a[i] = 9;
    ll sum1 = 9 * n;
    
    bool flag1 = false;
    for(ll i = n - 1; i >= 0; i--){
        
        while(a[i] > 0){
            if(isOk(s, sum1)) { flag1 = true; break; }

            --a[i];
            --sum1;
        }

    }

    forn(i,0,n) b[i] = 9;

    bool flag2 = false;
    ll sum2 = 9 * n;
    while(b[0] > 1){
            if(isOk(s, sum2)) { flag2 = true; break; }

            --b[0];
            --sum2;
    }

    if(!flag2)
        forn(i,1,n){
            
            while(b[i] > 0){
                if(isOk(s, sum2)) { flag2 = true; break; }

                --b[i];
                --sum2;
            }

        }

    forn(i,0,n) cout << b[i];
    cout << ' ';
    forn(i,0,n) cout << a[i];

}