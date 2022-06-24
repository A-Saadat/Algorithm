#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void)
{   
    intl n;
    cin >> n;

    while(true){
        n++;
        intl thousand = n / 1000;
        intl huundred = (n / 100) % 10;
        intl ten = (n / 10) % 10;
        intl one = n % 10;

        if(thousand != huundred and thousand != ten and thousand != one and huundred != ten and huundred != one and ten != one)
            break;
    }

    cout << n;

    return 0;
}