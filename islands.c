#include <stdio.h>
#include <stdbool.h>

#define MAX_M 300
#define MAX_N 300

// Directions: up, down, left, right
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

// Perform DFS to mark the entire island starting at (r, c) as visited.
void dfs(char grid[][MAX_N], int m, int n, int r, int c) {
    // Out of bounds or water cell → stop
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0')
        return;                                                   
    
    // Mark current land cell as visited (sink it)
    grid[r][c] = '0';                                             

    // Recurse on four neighbors
    for (int k = 0; k < 4; ++k) {
        dfs(grid, m, n, r + dr[k], c + dc[k]);                    
    }
}

// Returns the number of islands in the m×n grid.
int numIslands(char grid[][MAX_N], int m, int n) {
    int count = 0;                                               
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {                              
                ++count;                                       
                dfs(grid, m, n, i, j);                           
            }
        }
    }
    return count;                                                 
}

// Example driver
int main() {
    int m = 4, n = 5;
    char grid[MAX_M][MAX_N] = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    printf("Number of islands: %d\n", numIslands(grid, m, n));  
    return 0;
}
