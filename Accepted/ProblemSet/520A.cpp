#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void)
{
    intl n;
    cin >> n;   

    bool isAvail[100];

    for(intl i = 1; i <= 26; i++)
        isAvail[i] = false;

    char letter;
    for(intl i = 0; i < n; i++){
        intl j = 0;
        cin >> letter;

        if(letter >= 'a' and letter <= 'z'){
            j = letter - 96;
            isAvail[j] = true;
        } 
        else if(letter >= 'A' and letter <= 'Z'){
            j = letter - 64;
            isAvail[j] = true;
        }

    }

    for(intl i = 1; i <= 26; i++){
        if(!isAvail[i]){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}