#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i=k;i<n;i++) 
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
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll LIMIT = 1e8; 
bool isCheck[4];
ll a[def];
ll sum, mini = def;

int main (void)
{
    forn(i,0,3) cin >> a[i];

    forn(i,0,3){
        isCheck[a[i]] = true;
        ll checkingItem = a[i];
        
        sum = 0;
        forn(j,0,3){
            if(!isCheck[a[j]]){
                sum += abs(a[j] - checkingItem);
            }
        }

        mini = min(sum, mini);
        isCheck[a[i]] = false;
    }

    cout << mini;
}