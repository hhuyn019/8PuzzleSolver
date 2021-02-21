#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <tuple>

using namespace std;

int tilesMisplaced(vector<vector<int>> matrix) {
    int count = 0;
    if(matrix[0][0] != 1) {
        ++count;
    }
    if(matrix[0][1] != 2) {
        ++count;
    }
    if(matrix[0][2] != 3) {
        ++count;
    }
    if(matrix[1][0] != 4) {
        ++count;
    }
    if(matrix[1][1] != 5) {
        ++count;
    }
    if(matrix[1][2] != 6) {
        ++count;
    }
    if(matrix[2][0] != 7) {
        ++count;
    }
    if(matrix[2][1] != 8) {
        ++count;
    }
    if(matrix[2][2] != 0) {
        ++count;
    }
    return count;
}

int manhattan(vector<vector<int>> matrix) {
    // int x0, y0, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;
    int i, j, val, x, y, count = 0;

    // for(i=0; i<3; i++) {
    //     for(j=0; j<3; j++) {
    //         if(matrix[i][j]==0) {
    //             x0 = j;
    //             y0 = i;
    //         }
    //         if(matrix[i][j]==1) {
    //             x1 = j;
    //             y1 = i;
    //         }
    //         if(matrix[i][j]==2) {
    //             x2 = j;
    //             y2 = i;
    //         }
    //         if(matrix[i][j]==3) {
    //             x3 = j;
    //             y3 = i;
    //         }
    //         if(matrix[i][j]==4) {
    //             x4 =k
    //         }
    //     }
    // }
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            val = matrix[i][j];
            if(val != 0) {
                --val;
                x = val % 3;
                y = val / 3;
                count += abs(j-x) + abs(i-y);
            }
        }
    }
    return count;
}

int get_hn(vector<vector<int>> matrix, int option) {
    if(option == 1) { //uniform cost search
        return 0;
    } else if(option == 2) { //A* misplaced tile
        return tilesMisplaced(matrix);
    } else if(option == 3) { //A* manhattan
        return manhattan(matrix);
    }
    return -1;
}

void general_search(vector<vector<int>> matrix, int option) {
    int hn = get_hn(matrix, option);
    if(hn == -1) {
        cout << "Invalid option" << endl;
        return;
    } 
    //use tuple to initialize nodes 
    //use priority_queue to store nodes
    //expand
}

bool isDone(vector<vector<int>> matrix) {
    int count = 0;
    if(matrix[0][0] == 1) {
        ++count;
    }
    if(matrix[0][1] == 2) {
        ++count;
    }
    if(matrix[0][2] == 3) {
        ++count;
    }
    if(matrix[1][0] == 4) {
        ++count;
    }
    if(matrix[1][1] == 5) {
        ++count;
    }
    if(matrix[1][2] == 6) {
        ++count;
    }
    if(matrix[2][0] == 7) {
        ++count;
    }
    if(matrix[2][1] == 8) {
        ++count;
    }
    if(matrix[2][2] == 0) {
        ++count;
    }
    
    if(count == 9) {
        return true;
    } else {
        return false;
    }

}

int main() {
    vector<vector<int>> matrix;
    vector<int> rows(3);
    //string userInput;
    //int input1, input1, input3;
    int input;
    int i, j;

    cout << "Enter first row one value at a time: " << endl;
    for(i=0; i<3; i++) {
        cin >> input;
        rows[i] = input;
    }
    matrix.push_back(rows);

    cout << endl << "Enter second row one value at a time: " << endl;
    for(i=0; i<3; i++) {
        cin >> input;
        rows[i] = input;
    }
    matrix.push_back(rows);

    cout << endl << "Enter third row one value at a time: " << endl;
    for(i=0; i<3; i++) {
        cin >> input;
        rows[i] = input;
    }
    matrix.push_back(rows);

    cout << endl << "This is your matrix: " << endl;
    for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int option;

    cout << endl;
    cout << "Choose an algorithm" << endl;
    cout << "1. Uniform Cost Search" << endl;
    cout << "2. A* with the Misplaced Tile heuristic" << endl;
    cout << "3. A* with the Manhattan Distance heuristic" << endl; 

    cin >> option;
    while(option != 1 && option != 2 && option != 3) {
        cin >> option;
    }

    general_search(matrix, option);

    return 0;
}