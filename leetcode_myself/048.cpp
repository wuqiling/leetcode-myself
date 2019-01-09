#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::swap;
using std::vector;

void printArray(const vector<vector<int>>& m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) cout << m[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) { rotate_2(matrix); }

   private:
    // time O(N^2) space O(1)
    // runtime 4ms 72%
    void rotate_1(vector<vector<int>>& matrix) {
        // printArray(matrix);
        int N = matrix.size();
        if (N < 2) return;
        for (int i = 0; i < N / 2; i++) {
            for (int j = i; j < N - 1 - i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[N - 1 - j][i];
                matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];
                matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];
                matrix[j][N - 1 - i] = tmp;
            }
            // printArray(matrix);
        }
    }

    // time O(N^2) space O(1)
    // runtime 4ms 72%
    void rotate_2(vector<vector<int>>& matrix) {
        // printArray(matrix);
        int N = matrix.size();
        if (N < 2) return;

        //	----A		|	|
        //			=	|	|
        //  ----B		A	B
        for (int i = 0; i < N; i++)
            for (int j = 0; j < i; j++) swap(matrix[i][j], matrix[j][i]);
        // printArray(matrix);

        //	|	|		|	|
        //	|	|	=	|	|
        //	A	B		B	A
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N / 2; j++)
                swap(matrix[i][j], matrix[i][N - 1 - j]);
        // printArray(matrix);
    }
};

int main() {
    vector<vector<int>> matrix{
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

    Solution s;
    s.rotate(matrix);
    vector<vector<int>> matrix1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.rotate(matrix1);
    return 0;
}