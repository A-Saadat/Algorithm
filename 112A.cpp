#include <bits/stdc++.h>
using namespace std; 

#define intl long long int
     
int main (void)
{

    string a, b;
    cin >> a >> b;

    for(int i = 0; i < a.size(); i++){
        if((a[i] >= 'A' && a[i] <= 'Z'))
            a[i] = (char)(a[i] + 32);
        if(b[i] >= 'A' && b[i] <= 'Z')
            b[i] = (char)(b[i] + 32);
    }

    for(int i = 0; i < a.size(); i++){
        if(a[i] > b[i]){
            cout << 1;
            return 0;
        }
        else if(a[i] < b[i]){
            cout << -1;
            return 0;
        }
    }

    cout << 0; 
    return 0;
    
}
