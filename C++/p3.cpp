#include <iostream>
using namespace std;

/*
Repeated sort
*/
// bool swap(int *a1, int *a2) {
//     bool back = false;
//     int temp;
//     if (*a1 > *a2) {
//         temp = *a2;
//         *a2 = *a1;
//         *a1 = temp;
//         back = true;
//     }
//     return back;
// }

// int main()
// {

//     int n;
//     cin>>n;
//     int a[n];
//     int i_current = 0;
//     bool back;
//     bool cont_back;
//     cin>>a[0];
//     for(int i=1;i<n;i++) {
//         cin>>a[i];
//         back = swap(a+i-1,a+i);
//         if (back) {
//             for(int j=i-1;j>0;j--) {
//                 cont_back=swap(a+j-1,a+j);
//                 if (!cont_back){
//                     break;
//                 }
//             }
//         }
//     }
    
//     // print results
//     for(int i=0;i<n;i++) {
//         cout<<a[i]<<'\n';
//     }
//     return 0;
// }


/*
Quick sort
*/

void swap(int *a1, int *a2) {
    int *t;
    t = new int;
    *t = *a2;
    *a2 = *a1;
    *a1 = *t;
    delete t;
}

int *partition(int a[], int *lo, int *hi) {
    // choose pivot
    int *p = lo + int((hi - lo)/2);
    int pivot = *p;

    // left partition
    int *i = lo;

    // right partition
    int *j = hi;

    while (true) {
        while (*i < pivot) {i++;}
        while (*j > pivot) {j--;}

        if (i >= j) {
            break;
        }
        if (*j == *i) {
            i++; j--;
        } else {
            swap(i,j);
        }
    }
    return j;

    string s;
    char c[11+1];

    int n = 10;
    int n_0 = 0;
    int n_1 = 0;
    char c_0 = '0';
    char c_1 = '1';

    for (int i=0; i<n; i++) {
        c[i] = s[i];
        if (s[i] == c_0) {
            n_0++;
        } else {
            n_1++;
        }
    }

}

void quicksort(int a[], int *lo, int *hi) {
    if (lo >= &a[0] && hi >= &a[0] && lo < hi) {
        int *p = partition(a,lo,hi);
        quicksort(a,lo,p);
        quicksort(a,p+1,hi);
    }
}

void printa1(int a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printa2(int a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i] << endl;
    }
}

void geta(int a[], int length) {
    for (int i = 0; i < length; i++) {
        cin >> a[i];
    }
}

void gena(int a[], int length) {
    for(int i = 0; i < length; i++)
        a[i]=rand()%100000;   //Generate number between 0 to 99
}

int main()
{

    // int n; cin >> n;
    // int a[n]; geta(a,n);
    // quicksort(a,a,a+n-1);
    // printa2(a,n); // print results

    //---------- for dev ----------//
    // int n = 8;
    // int a[n] = {49,55,25,32,59,30,13,11};

    const int n = 1000000;
    int a[n];
    gena(a, n);
    cout << "input: ";
    // printa1(a,n);

    quicksort(a,a,a+n-1);
    
    // print results
    cout << "output: ";
    printa1(a,n);
    //-----------------------------//

    return 0;
}


// // We have populated the solutions for the 10 easiest problems for your support.
// // Click on the SUBMIT button to make a submission to this problem.

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {

//         int n;
//         cin>>n;
//          int a[n];
//         for(int i=0;i<n;i++)
//           cin>>a[i];
//             sort(a,a+n);
//             for(int i=0;i<n;i++)
//             cout<<a[i]<<'\n';
//     return 0;
// }

