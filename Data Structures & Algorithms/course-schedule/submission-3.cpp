class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> safe(numCourses);
        for(vector<int>& x: prerequisites){
            vector<bool> visiting(numCourses, false);
            visiting[x[0]] = true;
            if(!dfs(prerequisites, safe, visiting, x[1])) return false;
        }
        return true;
        
        
    }
    bool dfs(vector<vector<int>>& prerequisites, vector<bool>& safe, vector<bool>& visiting, int course){
        if(visiting[course]){ 
            return false;
        }
        if(safe[course]){
            return true;
        }
        for(vector<int>& x: prerequisites){
            if(x[0]==course){
                visiting[course]=true;
                if(!dfs(prerequisites, safe, visiting, x[1])) return false;
            }
        }
        safe[course]=true;
        return true;


    }
};
