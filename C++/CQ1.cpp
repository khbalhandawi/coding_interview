
#include <iostream>
using namespace std;


/*
 * Complete the 'minSwapsRequired' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 
 this can be done by iterating over two pointers one from the left and the other from the right
 need to do a check for possibility. If both 0 and 1 occur an odd number of times then a palindrome is not possible
 
 ill come back to this
 */

void swap(char* i, char* j) {
    char t = *i;
    *i = *j;
    *j = t;
}

int minSwapsRequired(string s) {
    int n = s.length();
    char* c;
    c = new char[n+1];
    int n0 = 0;
    int n1 = 0;
    char c0 = '0';
    char c1 = '1';
    
    for (int i=0; i<n; i++) {
        c[i] = s[i];
        if (s[i] == c0) {
            n0++;
        } else {
            n1++;
        }
    }
    
    if ((n0 % 2 != 0) && (n1 % 2 != 0)) {
        return -1;
    }
    
    int n_swaps = 0;
    char* left = c;
    char* right = c+n-1;
    
    while (left < right) {
        char* l = left; char* r = right;
        
        while (*l != *r) {
            r--;
        }
        if (l == r) {
            swap(r,r+1);
            n_swaps++;
            continue;
        }
        else {
            while(r < right) {
                swap(r, r+1);
                n_swaps++;
                r++;
            }
        }
        left++; right--;
    }
    return n_swaps;
}
int main()
{

    // string s = "101000";
    string s = "0101001";

    int result = minSwapsRequired(s);

    cout << result << endl;
    // fout << result << "\n";

    // fout.close();

    return 0;
}
