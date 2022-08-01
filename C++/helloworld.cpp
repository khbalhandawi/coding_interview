#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    
    int *p = nullptr;

    int s,t;
    cin >> s;
    cin >> t;
    int *a;
    a = new int[s*t];

    int *x;
    x = new int[s];

    for (int i=0; i<s; i++) {
        *x = i;
        x++;
        cin >> a[i];
    }

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    for (int i=0; i<s; i++) {
        x--;
    }
    delete[] x;

}