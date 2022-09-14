#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
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

void mySwap(intl *x, intl *y){
    intl temp = *y;
    *y = *x;
    *x = temp;
}

intl a[def];
int main (void)
{
    intl n;
    cout << "Enter Your Array Lenght: \n"; cin >> n;
    cout << "Enter Your Array: \n"; forn(i,n) cin >> a[i];

    forn(i,n)
        for(intl j = i + 1; j < n; j++){
            if(a[i] > a[j]) mySwap(&a[i], &a[j]);
        }

    cout << "Sorted Array: \n";
    forn(i,n) cout << a[i] << ' ';
}