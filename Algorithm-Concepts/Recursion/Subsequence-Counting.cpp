#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define forb(i,n,k) for(int i = (n - 1); i < k; i--) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define msi map<string, int> 
#define mci map<char, int> 
#define mll map<ll, ll> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
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

ll a[def];
ll n;
const ll LIMIT = 1e8; 

void Subsequence(ll n);
void Subsequence_Counter(ll n, ll x);

int main (void)
{
    cin >> n;
    Subsequence(n);
}

void Subsequence(ll n){
    Subsequence_Counter(n, 0);
}
void Subsequence_Counter(ll n, ll x){
    if(x == n){
        cout << "{ ";
        forn(i,0,n){
            if(a[i] == 1) cout << i + 1 << ' ';
        }
        cout << "}" << endl;
        return;
    }

    a[x] = 0;
    Subsequence_Counter(n, x + 1);

    a[x] = 1;
    Subsequence_Counter(n, x + 1);
}