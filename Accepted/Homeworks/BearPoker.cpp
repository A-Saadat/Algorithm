#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100000 

int main (void)
{
    intl n, bids[def];
    cin >> n;

    for (intl i = 0; i < n; i++)
    {
        cin >> bids[i];
        
        while (bids[i] % 3 == 0) // separate 3
            bids[i] /= 3;
        while (bids[i] % 2 == 0) // separate 2
            bids[i] /= 2;
    }

    for(int i = 0; i < n; i++) // Compare the array member
    {
        for(int j = i + 1; i < n; i++)
        {
            if(bids[i] != bids[j]){
                cout << "No" << endl;
                return 0;
            }
        }   
    }
    
    cout << "Yes" << endl;

}

// note: the bids can become equal if their base num is equal. so we separate the 2 & 3; whay? 
// because the only non-common membeer of the nums, must be 2 or 3;