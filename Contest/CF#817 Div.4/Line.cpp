#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define msi map<string, int> 
#define mci map<char, int> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define elif else if 
typedef long long int ll; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

vci a;
ll sum;

int main (void)
{
    ll t; cin >> t;
    while(t--){
        sum = 0;
        a.clear();

        ll n; cin >> n;
        forn(i,n){
            char c; cin >> c;

            if(c == 'L') a.pb(i);
            elif(c == 'R') a.pb((n - i) - 1);

            sum += a[i];
        }

        sort(a.begin(), a.end());

        forn(i,n){

            ll tmp = sum;
            ll b = n - a[i] - 1;

            tmp += (b - a[i]);
            if(tmp > sum) sum = tmp;

            cout << sum << ' ';
        }

        cout << endl;

    }
}