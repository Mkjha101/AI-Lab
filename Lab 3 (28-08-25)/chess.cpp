// Add code for this AI Lab program
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n = 3; // Number of rows
int m = 3; // Number of columns
vector<vector<int>> board(n, vector<int>(m, 0)); // Initialize a 3x3 chess board with zeros
int maxSum = INT_MIN; // Variable to store the maximum sum found
// Directions for knight moves
vector<pair<int, int>> directions = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
bool isSafe(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 0);
}
void knightTour(int x, int y, int moveCount, int currentSum) {
    // Try all knight moves from (x,y). If no move is possible, treat this as a terminal
    // path and update maxSum with the current accumulated sum.
    bool moved = false;
    for (auto dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;
        if (isSafe(newX, newY)) {
            moved = true;
            board[newX][newY] = 1; // Mark the cell as visited
            // Add the visited cell's value (newX + newY) to the current sum
            knightTour(newX, newY, moveCount + 1, currentSum + (newX + newY));
            board[newX][newY] = 0; // Backtrack
        }
    }
    // If no further moves, update maxSum with currentSum (dead-end / terminal state)
    if (!moved) {
        maxSum = max(maxSum, currentSum);
    }
}
int main() {
    board[0][0] = 1; // Start from the top-left corner
    // Include starting cell's value (0 + 0) in the initial sum. For readability we
    // show the intention of counting the starting cell.
    int startValue = 0 + 0;
    knightTour(0, 0, 1, startValue); // Start the knight's tour
    cout << "Maximum sum of visited cells: " << maxSum << endl;
    return 0;
}