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

string Binary(int x) {
    string t;
    while(x > 0){
        if(x % 2 == 0)
            t += "0";
        else
            t += "1";

        x /= 2;
    }

    intl size = t.size();

    string ans;
    for(intl i = size; i >= 0; i--)
        ans += t[i];

    return ans;
}

int main (void)
{

}