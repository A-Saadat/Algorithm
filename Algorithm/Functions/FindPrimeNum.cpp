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

vci findPrime(int x){
    bool notPrime[def];
    vci primeNum;

    for(intl i = 2; i <= x; i++){
        for(intl j = i * i; j <= x; j+=i){
            notPrime[j] = true;
        }
    }
    forn(i,x) if(!notPrime[i]) primeNum.pb(i);

    return primeNum;
}

int main (void)
{

}