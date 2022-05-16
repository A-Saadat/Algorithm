#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100000



int main (void)
{
    intl n;
    cin >> n;
    bool Check[def];
    
    intl LC[def], Beauti[def];

    for (intl i = 0; i <= n ; i++)
    {
        Check[i] = false;
        Beauti[i] = 0;
    }
    
    for(intl i = 2; i <= n; i++) // define the prime nums
    {
        if(Check[i] == true)
            continue;
        else{
            for(int j =  i * i; j <= n; j += i){
                if (Check[j] == false){
                    LC[j] = i;
                    Check[j] = true;
                }
            }
        }
    }

    for(intl i = 2; i <= n; i++)
    {
        if(Check[i] == false)
            Beauti[i] = i;
        else{
            Beauti[i] = LC[i] + Beauti[i / LC[i]]; // 36 = 2 + Beauti(18); 
        }
    }
    
    intl sum = 0;
    for(intl i = 2; i <= n; i++)
        sum += Beauti[i];

    cout << sum << endl;
}

// note: Beauti of a n number, is LC of numeber + Beauti of the (n / lC)