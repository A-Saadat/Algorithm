#include <bits/stdc++.h> 

using namespace std; 

#define intl long long int 

int luckyNum[] = {4, 7, 47, 74, 444, 474, 477, 744, 774, 777};

int main (void)
{
    int n;
    cin >> n;

    for(int i = 0; i < 10; i++){
        if(n % luckyNum[i] == 0){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO";
    return 0;
}