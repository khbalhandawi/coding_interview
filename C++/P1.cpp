#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int main()
{
	int P[4];
	for(int i=0; i < 4; i++) {
        cin >> P[i];
	    assert((P[i] >= 1) && (P[i] <= 100));
	}
	
	int n_weeks = 0;
	for(int i=0; i < 4; i++) {
	    if (P[i] >= 10) {
	        n_weeks++;
	    }
	}
	
    cout << n_weeks << endl;
	
	return 0;

}