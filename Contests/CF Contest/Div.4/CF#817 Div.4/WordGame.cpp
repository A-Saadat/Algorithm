#include <bits/stdc++.h> 
using namespace std; 

#define def 1000
#define forn(i,n) for(int i=0;i<n;i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define msi map<string, int> 
#define mci map<char, int> 
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

msi freq;
string a[def][def];
intl score[def];

int main (void)
{
    intl t; cin >> t;

    while(t--){
        freq.clear();
        forn(i,3) score[i] = 0;

        intl n; cin >> n;

        forn(i,3){
            forn(j,n){
                cin >> a[i][j];
                string tmp = a[i][j];

                freq[tmp]++;
            }
        }

        forn(i,3){
            forn(j,n){
                string tmp = a[i][j];

                if(freq[tmp] == 1) score[i] += 3;
                elif(freq[tmp] == 2) score[i] += 1;
            }
        }

        forn(i,3) cout << score[i] << ' ';
        cout << endl;
    }
}