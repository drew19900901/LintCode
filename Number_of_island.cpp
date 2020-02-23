/**
    Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

    Find the number of islands.
    Input:
    [
        [1,1,0,0,0],
        [0,1,0,0,1],
        [0,0,0,1,1],
        [0,0,0,0,0],
        [0,0,0,0,1]
    ]
    output:3
    

    Solution : DFS  and use visited = true / false
**/


class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    void dfs(vector<vector<bool>> &grid,int i,int j){
        if(i<0||i>=grid.size()) return;
        if(j<0||j>=grid[0].size()) return;
        if(!grid[i][j]) return;
        grid[i][j]=false;
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        
    }
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        int result=0;
        if(grid.empty()||grid[0].empty()){
            return result;
        }
        int row = grid[0].size();
        int column = grid.size();
       
        for(int i =0 ;i<column ;++i){
            for(int j=0;j<row;++j){
                if(grid[i][j]){
                    dfs(grid,i,j);
                    result++;
                }
            }
        }
        return result;
        
    }
    
};