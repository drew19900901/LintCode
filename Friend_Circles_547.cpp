// DFS
class Solution {
private:
    vector<int> visited;
    int friendsSize;
    
public:
    int findCircleNum(vector<vector<int>>& M) {
        int result=0;
        friendsSize = M.size();
        visited = vector<int>(friendsSize,0);
        for(int i =0;i<friendsSize;++i){
            if(visited[i]==1){
                continue;
            }
            dfs(M,i);
            ++result;
        }
        return result;
    }
    void dfs(vector<vector<int>>& M, int curFriend){
        for(int i =0; i<friendsSize;++i){
            if(M[curFriend][i]==1 && visited[i]==0){
                visited[i]=1;
                dfs(M,i);
            }
        }
    }
};

//BFS

class Solution {
private:
    vector<int> visited;
    queue<int> friends_queue;
    int friends_size;
public:
    int findCircleNum(vector<vector<int>>& M) {
        int result=0;
        friends_size = M.size();
        visited = vector<int>(friends_size,0);
        for(int i =0;i<friends_size;++i ){
            if(visited[i]==0){
                friends_queue.push(i);
                while(!friends_queue.empty()){
                    int current=friends_queue.front();
                    friends_queue.pop();
                    visited[current] = 1;
                    for(int j =0;j<friends_size;++j){
                        if(M[current][j]==1 && visited[j]==0){
                            friends_queue.push(j);
                        }
                    }
                }
                result++;
            }
            
        }
        return result;
    }
};