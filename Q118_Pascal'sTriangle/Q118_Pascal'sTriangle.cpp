#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ivec;

    for (int i = 0; i < numRows; i++) {
        ivec.push_back(vector<int>());

        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                ivec[i].push_back(1);
            }
            else if (j != 0 && j != i) {
                int num = ivec[i - 1][j - 1] + ivec[i - 1][j];
                
                // Breakpoint with __asm
                __asm int 3;
                ivec[i].push_back(num);
            }
        }
    }

    return ivec;
}

int main()
{
    vector<vector<int>> vec = generate(5);

    // Printing
    for (auto& c : vec) {
        for (auto& c1 : c) {
            cout << c1 << " ";
        }
        cout << endl;
    }


    return 0;
}