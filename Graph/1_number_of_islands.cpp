/*
 * Solution Summary:
 * This solution counts the number of islands in a grid. An island is a group of connected `1`s (land)
 * surrounded by water (`0`). The algorithm uses BFS to explore all land cells connected to a starting
 * cell, marking them as visited. For each BFS call, the count of islands is incremented.
 */

class Solution
{
public:
    // Helper function to check if a cell is valid and unvisited
    bool isValid(vector<vector<char>> &grid, int r, int c)
    {
        int row = grid.size();
        int col = grid[0].size();
        return (r >= 0 && r < row && c >= 0 && c < col && grid[r][c] == '1');
    }

    // BFS to traverse and mark all cells in the current island
    void bfs(vector<vector<char>> &grid, int row, int col)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = '2'; // Mark the current cell as visited

        // Directions for moving up, left, down, and right
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while (!q.empty())
        {
            auto [r, c] = q.front(); // Get the current cell
            q.pop();

            // Check all 4 possible directions
            for (auto [dr, dc] : directions)
            {
                int nr = r + dr, nc = c + dc;
                if (isValid(grid, nr, nc))
                {
                    q.push({nr, nc});
                    grid[nr][nc] = '2'; // Mark the cell as visited
                }
            }
        }
    }

    // Main function to count the number of islands
    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        int rows = grid.size(), cols = grid[0].size();

        // Traverse every cell in the grid
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // Start BFS if a land cell (`1`) is found
                if (grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    islands++; // Increment the island count
                }
            }
        }
        return islands; // Return the total number of islands
    }
};
