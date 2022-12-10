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
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define scan(a, n) for(int i = 0; i < n; i++) cin >> a[i]; 
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

const ll def = 10; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll Diagnal1[9][9], Diagnal2[9][9], Vertical[9][9], Horizontal[9][9]; 

void Forming_the_Table(){

    // ? Diagonal 1
    forn(i,0,8){
        ll k = 0, idx = 1;
        for(ll j = i; (i + k <= 8 && j + k <= 8); j++){
            // cout << i + k << ' ' << j << endl;
            Diagnal1[i + k][j] = idx, ++k;
            ++idx;
        } 

        cout << "---------------------\n";
    }

    forn(i,0,8){
        forn(j,0,8) cout << Diagnal1[i][j] << ' ';
        cout << endl;
    }

}

main ()
{IOS;

    Forming_the_Table();

}