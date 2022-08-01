#include <iostream>
using namespace std;

struct testCase {
    int n_prob;
	int * diffs;
};

int main() {
	// your code goes here
	
	int n_tests;
	cout << "enter number of tests "<< endl;
	cin >> n_tests;

	testCase* tests;
	tests = new testCase[n_tests];

	for (int i = 0; i < n_tests; i++) {
		cout << "enter number of problems "<< endl;
		cin >> tests[i].n_prob;
		tests[i].diffs = new int[tests[i].n_prob]; // allocate memory for prob vector

		cout << "enter " << tests[i].n_prob << " problems" << endl;
		for (int j = 0; j < tests[i].n_prob; j++) {
			// scanf("%d", &tests[i].diffs[j]);
			cin >> tests[i].diffs[j];
		}
	}
	// x = new int[n_prob];
	int sum;
	for (int i = 0; i < n_tests; i++) {
		sum = 0;
		for (int j = 0; j < tests[i].n_prob; j++) {
			if (tests[i].diffs[j] >= 1000) {
				sum++;
			}
		}
		cout << sum << endl;
	}

	return 0;
	
}
