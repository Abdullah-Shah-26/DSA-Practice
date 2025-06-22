#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

int main() {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //rows=>mat.size()
    //cols=mat[i].size()

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
