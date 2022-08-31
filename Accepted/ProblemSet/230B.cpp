#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define elif else if 
typedef long long int intl; 
typedef vector<intl> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

bool notPrime[def];
vci primeNum;
intl a[def];

int main (void)
{
    intl n; cin >> n;
    forn(i,n) cin >> a[i];

    for(intl i = 2; i <= 1e6; i++){
        for(intl j = i * i; j <= 1e6; j+=i){
            notPrime[j] = true;
        }
    }
    forn(i,1e6) if(!notPrime[i]) primeNum.pb(i);

    forn(i,n){

        if(a[i] == 1){
            cout << "NO" << endl;
            continue;
        }

        bool flag = false;   
        intl L = -1, R = primeNum.size();

        while(R - L > 1){
            intl MID = L + ((R - L) / 2);

            intl p = primeNum[MID] * primeNum[MID];

            if(p > a[i]){
                R = MID;
            }
            elif(p <= a[i]){
                L = MID;
            }
            cout << " L " << L << " R " << R << endl;
            if(a[i] == p){
                flag = true;
                break;
            }
        }

        if(L * L == a[i] or flag) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}