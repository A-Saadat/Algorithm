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

const ll LIMIT = 1e8; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[def];
ll Counter[def];

int main (void)
{
    ios_base::sync_with_stdio(false);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        forn(i,0,n) cin >> a[i];
        forn(i,0,n) Counter[a[i]] = 0;
        forn(i,0,n) Counter[a[i]]++;

        ll L = -1, R = LIMIT;
        while(R - L > 1){
            bool isOk = false;
            ll cnt = 0;
            ll MID = (R + L) / 2;

            forn(i,0,n){
                if(Counter[a[i]] >= MID) isOk = true;
                if(Counter[a[i]] == 1) cnt++;
            }

            if(cnt >= MID && isOk) L = MID;
            else R = MID;
        }

        cout << L << endl;
    }
}


// ! Debug Hint:
// ? مشکل اینه که تو. برای پیدا کردن اعضای گروه متمایز ها، درنظر نگرفتی که ممکنه از اعضای گروه تکراری ها هم استفاده کنی :)