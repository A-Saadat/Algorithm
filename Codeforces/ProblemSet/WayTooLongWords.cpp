#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int
#define def 100000

int main ()
{

    intl n;
    string a;
    cin >> n;

    for(int i = 0; i < n; i++)
    { 
        cin >> a;
        
        if(a.length() > 10)
            cout << a[0] << a.length() - 2 << a[a.length() - 1] << endl;

        else   
            cout << a << endl;
    }

    
    

}