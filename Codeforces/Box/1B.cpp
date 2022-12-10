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

ll a[def], Pr[def];

bool findTheType(string s){
    if(s[0] == 'R' && s[1] != 'C') return 1;
    else return 0;
}

ll Number_Of_Digit(ll x){
    ll idx = 0;
    while(true){

        if(Pr[idx] >= x && x > Pr[idx - 1]) return idx;

        ++idx;
    }
}

string Type_Conversion(ll x){
    ll z = x % 26;
    // cout << x - z;
    ll NOD = Number_Of_Digit(x) - 1;
    ll sum = (x - z) / 26;
    // cout << NOD << ' ' << sum << endl;
    vci arr; ll mk = 0;
    forn(i,0,NOD) arr.pb(26), mk += 26;
    for(ll i = arr.size() - 1; i >= 0; i--){
        // cout << arr[i] << ' ';
        while(arr[i] > 1 && mk != sum) {
            // cout << arr[i] << ' '<< mk << endl;
            arr[i]--; mk--;
        }
    }

    string ans;

    forn(i,0,arr.size()){
        // cout << (char) (arr[i] + 64) << ' ';
        ans += (char) (arr[i] + 64);
    }
    ans += (char) (z + 64);

    return ans;
}

string TYPE1(string s){
    ll n = s.size();
    ll idx = 0;
    forn(i,0,n){
        ll x = (int) s[i];
        if(x < 65) { idx = i; break; }
    }

    string col;
    forn(i,0,idx){
        col += s[i];
    }
    ll d = Pr[col.size() - 1];
    // forn(i,0,10) {
    //     cout << d << ' ' << Type_Conversion(d) << endl; ++d;
    // }
    // cout << d << ' ';
    // cout << col << ' ';

    string ans = "R";
    forn(i,idx,n) ans += s[i];
    ans += "C";

    stringstream ss;
    ss << col;
    string str = ss.str();
    forn(i,0,str.size()) ans += str[i];

    return ans;

}

string TYPE2(string s){
    ll n = s.size();
    string col;
    ll idx = 0;
    forn(i,0,n){
       if(s[i] == 'C') { idx = i; break;}
    }

    forn(i,idx + 1,n) col += s[i];
    ll coll = atoi( col.c_str() );
    
    string ans = Type_Conversion(coll);
    
    forn(i,1,n){
        if(s[i] == 'C') break;
        ans += s[i];
    }

    return ans;
}

main ()
{IOS;

    Pr[0] = 1;
    forn(i,1,1e4) Pr[i] = Pr[i - 1] * 26;

    ll t; cin >> t;
    while(t--){
        string s; cin >> s;
        ll type = findTheType(s);
        if(!type) cout << TYPE1(s) << endl;
        else cout << TYPE2(s) << endl;
    }

}