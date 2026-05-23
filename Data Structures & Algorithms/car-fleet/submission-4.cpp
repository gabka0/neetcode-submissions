class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();

        for(int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<>());

        vector<double> times;  // changed to double
        for(auto& car: cars){
            times.push_back((double)(target - car.first) / car.second);  // cast added
        }

        stack<double> stck;  // changed to double
        int ans = 0;

        for(double& time: times){
            if(stck.empty() || time > stck.top()){
                ans++;
                stck.push(time);
            }
        }

        return ans;
    }
};