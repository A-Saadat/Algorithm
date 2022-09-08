#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 1000000 

int main (void)
{
    intl t;
    cin >> t;
    
    intl a, b;
    for(intl i = 0; i < t; i++){
        cin >> a >> b;

        while(true){
            if(a % b == 0){
                cout << 0 << endl;
                break;
            }
            else{
                intl r = a % b;
                cout << b - r << endl; 
                break;
                // ? at the end we need to find the value that we need to make a divisible to be; so if we subtract the second num from divid remaining 
                // ? we get the the ans => exmp: 80 / 9 => r = 1, res = 8; in this exmp we need 1 more to make r equal to b(second num) :))
            }
        }

    }

}