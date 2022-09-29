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
mll m; 
ll a[def];
si test;

int main (void)
{   
    ll n; cin >> n;
    forn(i,0,n){
        cin >> a[i];
        m[ a[i] ]++;
        test.insert(a[i]);
    }

    if(test.size() < 3) { cout << 0; return 0; }

    ll teamN = LIMIT;
    fort(itr, m) teamN = min(teamN, itr->S);
    cout << teamN << endl;

    forn(i,0,teamN){
        ll cnt1 = 0, cnt2 = 0, cnt3 = 0;    

        forn(j,0,n){
            if(a[j] == 1 and cnt1 == 0){
            cout << j + 1 << ' ';
            a[j] = LIMIT;
            cnt1++;
            }

            elif(a[j] == 2 and cnt2 == 0){
                cout << j + 1 << ' ';
                a[j] = LIMIT;
                cnt2++;
            }

            elif(a[j] == 3 and cnt3 == 0){
                cout << j + 1 << ' ';
                a[j] = LIMIT;
                cnt3++;
            }
        }

        cout << endl;

    }
}