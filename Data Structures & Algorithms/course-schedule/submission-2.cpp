class Solution {
public:
unordered_map<int, vector<int>> preMap;
unordered_set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }
        for (vector<int> prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }
        for(int i =0; i<numCourses; i++){
            if(!dfs(i)){
                return false;
            }
        }
        return true;

    }
    bool dfs(int course){
        if(visiting.count(course)){
            return false;
        }
        if(preMap[course].empty()){
            return true;
        }
        visiting.insert(course);
        for(int pres: preMap[course]){
            if (!dfs(pres)) {
                return false;
            }
        }
        visiting.erase(course);
        preMap[course].clear();
        return true;

    }
};
