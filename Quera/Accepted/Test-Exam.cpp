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

const ll LIMIT = 1e4; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const char ansChecker[] = {'A', 'B', 'C', 'D'};

char ans[def];
char a[LIMIT][LIMIT];
ll checker[def];

int main (void)
{IOS;

    ll n; cin >> n;
    forn(i,0,n) cin >> ans[i];

    ll t; cin >> t;
    while(t--){

        forn(i,0,n) checker[i] = 0;

        forn(i,0,n){
            ll cnt = 0;
            forn(j,0,4) {
                cin >> a[i][j];
                if(a[i][j] == '#') checker[i] = j + 1, cnt++;
            }
            if(cnt >= 2) checker[i] = -1;
        }

        ll cr_ans = 0, fa_ans = 0;
        forn(i,0,n){
            if(checker[i] == -1) { ++fa_ans; continue; }
            elif(checker[i] == 0) continue;

            if(ansChecker[ checker[i] - 1] == ans[i]) ++cr_ans;
            elif(ansChecker[ checker[i] - 1] != ans[i] ) ++fa_ans;
        }

        cout << 3 * cr_ans - fa_ans << endl;
    }


}