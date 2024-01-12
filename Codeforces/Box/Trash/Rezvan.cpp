#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false) 
#define msi map<string, int> 
#define mci map<char, int> 
#define mll map<ll, ll> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define elif else if 
typedef long long int ll; 
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll LIMIT = 1e8; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main (void)
{IOS;

    double a, aPow, b, bPow, c, cPow, cDb; cin >> a >> aPow >> b >> bPow >> c >> cPow >> cDb;
    a = pow(a, aPow); b = pow(b, bPow); c = pow(c, cPow) * cDb;

    // cout << a << ' ' << b << ' ' << c;
    double del = pow(b, 2) - (4 * a * c);

    double X1 = ((-1 * b) + sqrt(del)) / (2 * a);
    double X2 = ((-1 * b) - sqrt(del)) / (2 * a);

    // cout << log(1e12);
    cout << X1 << ' ' << X2 << endl;
}