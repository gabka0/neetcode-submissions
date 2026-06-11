class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>> time;
        for(int i=0; i<position.size();i++){
            time.push_back({position[i], ((float)target-position[i])/speed[i]});
        }
        sort(time.begin(), time.end(), [](auto& a, auto& b) {
    return a.first > b.first;
});
        int fleets=0;
        int x = 0;
        while(x<time.size()){
            fleets+=1;
            while(x<time.size()-1 && time[x].second>=time[x+1].second) {
                time[x+1].second = time[x].second;
                x++;
            }
            x++;
        }
        return fleets;
    }
};
