/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

//Merge-Sort
// split array into two halfs
//Pass half-arrays to merge-sort() recursively

void merge(int a[], int start, int mid, int end) {
    int ln = mid-start+1;
    int rn = end-mid-1;
    
    int la[ln];
    int ra[rn];
    
    for(int i=0; i<ln; i++)
        la[i] = a[start+i];
    for(int i=0; i<rn; i++)
        ra[i] = a[mid+1+i];
    
    int i{0}, j{0};
    int k = start;
    while( i < ln && j < rn ) {
        if(la[i] < ra[j]) {
            a[k] = la[i];
            i++;
            k++;
        }
        else {
            a[k] = ra[j];
            j++;
            k++;
        }
    }
    
    while( i < ln ) {
        a[k] = la[i];
        i++;
        k++;        
    }
    
    while( j < rn ) {
        a[k] = ra[j];
        j++;
        k++;        
    }    
}

void mergeSort(int a[], int start, int end) {
    if(start>=end) return;
    
    int mid = (end-start)/2;
    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);
    
    merge(a, start, mid, end);
}

void printA(int a[], int N) {
    for(int i=0; i<N; i++)
        cout << a[i] << "\t";
    cout << "\n";
}

int main()
{
    printf("Hello World \n");
    
    int a[6]{5, 2, 1, 3, 4, 6};
    
    printA(a, 6);
    mergeSort(a, 0, 5);
    printA(a, 6);
    

    return 0;
}
