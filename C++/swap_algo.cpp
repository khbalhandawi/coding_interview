#include <iostream>    // std::find_if
#include <vector>    // std::vector
#include <string>    // std::string, std::getline
#include <fstream>    // std::ofstream
#include <algorithm>    // std::find_if
#include <numeric>
#include <iterator>
#include <functional>
#include <cctype>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */

vector<int> joinTrees(vector<int> l, int node, vector<int> r) {
    vector<int> traversal = l;
    traversal.push_back(node);
    traversal.insert(traversal.end(), r.begin(), r.end());

    return traversal;
}

vector<int> Traverse(vector<vector<int>> indexes, int node = 1) {
    if (node == -1) return {};
    int l = indexes[node-1][0]; 
    int r = indexes[node-1][1];

    vector <int> l_subtree = Traverse(indexes, l);
    vector <int> r_subtree = Traverse(indexes, r);
    vector<int> traversal = joinTrees(l_subtree, node, r_subtree);
    return traversal;
}

void Swap(vector<vector<int>>* indexes, int swapLevel, int level = 1, int node = 1) {
	if (node == -1) return;
    int l = indexes->at(node-1)[0];
    int r = indexes->at(node-1)[1];
	if (level % swapLevel == 0) {
        int temp = (*indexes)[node-1][0];
        (*indexes)[node-1][0] = (*indexes)[node-1][1];
        (*indexes)[node-1][1] = temp;
	}
	Swap(indexes, swapLevel, level+1, l);
	Swap(indexes, swapLevel, level+1, r);
}

vector<int>  SwapTraverse(vector<vector<int>>* indexes, int swapLevel, int level = 1, int node = 1) {
	if (node == -1) return {};
    int l = indexes->at(node-1)[0];
    int r = indexes->at(node-1)[1];
    vector <int> l_subtree;
    vector <int> r_subtree;
	if (level % swapLevel == 0) {
        int temp = (*indexes)[node-1][0];
        (*indexes)[node-1][0] = (*indexes)[node-1][1];
        (*indexes)[node-1][1] = temp;
        l_subtree = SwapTraverse(indexes, swapLevel, level+1, r);
	    r_subtree = SwapTraverse(indexes, swapLevel, level+1, l);
	}
    else {
        l_subtree = SwapTraverse(indexes, swapLevel, level+1, l);
	    r_subtree = SwapTraverse(indexes, swapLevel, level+1, r);
    }

    vector<int> traversal = joinTrees(l_subtree, node, r_subtree);
    return traversal;
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {

    vector<vector<int>> traverse_matrix;
    vector<int> traverse;
    
    for (size_t j = 0; j < queries.size(); j++) {
        int swapLevel = queries[j];
        // Swap(&indexes, swapLevel);
        // traverse = Traverse(indexes);
        traverse = SwapTraverse(&indexes, swapLevel);
        traverse_matrix.push_back(traverse);
    }

    return traverse_matrix;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));
    ofstream fout("out.txt");

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);})
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](int c) {return !std::isspace(c);}).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
