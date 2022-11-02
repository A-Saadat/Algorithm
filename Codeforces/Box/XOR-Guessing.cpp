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
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll Binary_to_int(vci s);
string int_to_Binary(ll x);
void Binary_String_Lenght(ll n);

vci R, L, a;
bool flag;
ll x, y;

int main (void)
{IOS;

    Binary_String_Lenght(7);
    cout << "? ";
    forn(i,0,100) cout << R[i] << ' ';
    cout << endl;

    cin >> x;
    string x1 = int_to_Binary(x);

    flag = true;
    Binary_String_Lenght(7);
    cout << "? ";
    forn(i,2,102) cout << L[i] << ' ';
    cout << endl;

    cin >> y;
    string y1 = int_to_Binary(y);

    if(x1.size() <= 14){
        reverse(x1.begin(), x1.end());
        while(x1.size() < 14) x1 += '0';
        reverse(x1.begin(), x1.end());
    } 

    if(y1.size() <= 14){
        reverse(y1.begin(), y1.end());
        while(y1.size() < 14) y1 += '0';
        reverse(y1.begin(), y1.end());
    } 
    
    string an = "";
    forn(i,0,7) an += y1[i];
    forn(i,7,14) an += x1[i];

    ll n = an.size();
    ll ans = 0;
    reverse(an.begin(), an.end());
    forn(i,0,n)
        if(an[i] == '1') ans += (1 << i);

    cout << "! " << ans;

}

void Binary_String_Lenght(ll n){
    if(n <= 0){
        forn(i,0,7) a.pb(0);
        if(flag){
            reverse(a.begin(), a.end());
            L.pb(Binary_to_int(a)); 
            reverse(a.begin(), a.end());
        } 
        else R.pb(Binary_to_int(a));

        forn(i,0,7) a.pop_back();
    }
    else{
        a.pb(1);
        Binary_String_Lenght(n - 1);
        a.pop_back();

        a.pb(0);
        Binary_String_Lenght(n - 1);
        a.pop_back();
    }

    return;
}

ll Binary_to_int(vci s){
    ll n = s.size();
    ll ans = 0;
    reverse(s.begin(), s.end()--);
    forn(i,0,n)
        if(s[i] == 1) ans += pow(2, i);

    return ans;
}

string int_to_Binary(ll x) {
    string t;
    while(x > 0){
        if(x % 2 == 0)
            t += "0";
        else
            t += "1";

        x /= 2;
    }

    ll size = t.size();

    string ans;
    for(ll i = size; i >= 0; i--)
        ans += t[i];

    return ans;
}