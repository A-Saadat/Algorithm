#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
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

intl a[def];

void MergeSort(intl arr[], intl len);

void Merge(intl leftArr[], intl leftArrSize, intl rightArr[], intl rightArrSize, intl mainArr[]);

int main (void)
{
    intl n;
    cout << "Enter Your Array Lenght: \n"; cin >> n;
    cout << "Enter Your Array: \n"; forn(i,n) cin >> a[i];

    MergeSort(a, n);

    cout << "Sorted Array: \n";
    forn(i,n) cout << a[i] << ' ';
}

void MergeSort(intl arr[], intl len){
    intl mid = len / 2;
    intl b[def];
    intl c[def];
    intl bSize = mid, cSize = (len - mid);

    if(len < 2) return;

    forn(i,mid) b[i] = a[i];
    for(intl i = mid; i < len; i++){
        c[i - mid] = a[i];
    }

    MergeSort(b, mid);
    MergeSort(c, (len - mid));

    Merge(b, bSize, c, cSize, arr);
}

void Merge(intl leftArr[], intl leftArrSize, intl rightArr[], intl rightArrSize, intl mainArr[]){
    intl i = 0, j = 0, k = 0;

    while((i < leftArrSize) && (j < rightArrSize)){
        if(leftArr[i] <= rightArr[i]){
            mainArr[k] = leftArr[i];
            i++;
        } else{
            mainArr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < leftArrSize){
        mainArr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < rightArrSize){
        mainArr[k] = rightArr[j];
        j++;
        k++;
    }
}