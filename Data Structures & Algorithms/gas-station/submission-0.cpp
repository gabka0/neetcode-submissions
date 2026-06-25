class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int t_gas = 0;
        int t_cost = 0;
        for(auto& x: gas){
            t_gas+=x;
        }
        for(auto& x: cost){
            t_cost+=x;
        }
        if(t_cost>t_gas) return -1;
        int res = 0;
        int total=0;
        for(int i=0; i<gas.size();i++){
            total+=(gas[i]-cost[i]);
            if(total<0){
            res=i+1;
            total = 0;
             }
        }
        return res;
        

        
    }
};
