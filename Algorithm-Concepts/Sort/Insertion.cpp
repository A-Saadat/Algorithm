#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
#define forn(i,n) for(int i=1;i<n;i++) 
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

intl a[def];

int main (void)
{
    intl n;
    cout << "Enter Your Array Lenght: \n"; cin >> n;
    cout << "Enter Your Array: \n"; forn(i,n) cin >> a[i];


    forn(i,n){
        intl CURRENT = a[i];
        intl j = i - 1;

        while(j >= 0 and CURRENT < a[j]){
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = CURRENT; 
    }


    cout << "Sorted Array: \n";
    forn(i,n) cout << a[i] << ' ';
}