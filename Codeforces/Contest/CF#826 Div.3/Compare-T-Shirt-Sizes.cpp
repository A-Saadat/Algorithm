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
{
    ios_base::sync_with_stdio(false);

    ll t; cin >> t;
    while(t--){
        string T1, T2; cin >> T1 >> T2;
        ll nT1 = T1.size() - 1, nT2 = T2.size() - 1;

        if(T1[nT1] == 'L' && T2[nT2] == 'L'){
            if(nT1 > nT2) cout << '>' << endl;
            elif(nT1 < nT2) cout << '<' << endl;
            elif(nT1 == nT2) cout << '=' << endl;
        }
        elif(T1[nT1] == 'L' && T2[nT2] == 'S') cout << '>' << endl;
        elif(T1[nT1] == 'S' && T2[nT2] == 'L')cout << '<' << endl;
        elif(T1[nT1] == 'S' && T2[nT2] == 'S'){
            if(nT1 > nT2) cout << '<' << endl;
            elif(nT1 < nT2) cout << '>' << endl;
            elif(nT1 == nT2) cout << '=' << endl;
        }
        elif(T1[nT1] == 'L' && T2[nT2] == 'M') cout << '>' << endl;
        elif(T1[nT1] == 'S' && T2[nT2] == 'M') cout << '<' << endl;
        elif(T1[nT1] == 'M' && T2[nT2] == 'S') cout << '>' << endl;
        elif(T1[nT1] == 'M' && T2[nT2] == 'L') cout << '<' << endl;
        elif(T1[nT1] == 'M' && T2[nT2] == 'M') cout << '=' << endl;

        // ll x = 1, y = 1;
        // if(T1[nT1] == 'L') x *= (nT1 > 0 ? nT1 : nT1 + 1);
        // elif(T1[nT1] == 'S') x *= ((nT1 > 0 ? nT1 : nT1 + 1) * -1);
        // elif(T1[nT1 - 1] = 'M') x = 0;
 
        // if(T2[nT2] == 'L') y *= (nT2 > 0 ? nT2 : nT2 + 1);
        // elif(T2[nT2] == 'S') y *= ((nT2 > 0 ? nT2 : nT2 + 1) * -1);
        // elif(T2[nT2] = 'M') y = 0;
 
 
        // if(x > y) cout << '>' << endl;
        // elif(x < y) cout << '<' << endl;
        // elif(x == y) cout << '=' << endl;
    }
}