class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> cars;
        int n = position.size();

        for(int i=0;i<n;i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end(), greater<>());

        double lastTime = 0;
        int fleets = 0;

        for(auto &car : cars){
            double time = (double)(target - car.first) / car.second;

            if(time > lastTime){
                fleets++;
                lastTime = time;
            }
        }

        return fleets;
    }
};