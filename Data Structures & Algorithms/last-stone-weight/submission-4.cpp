class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> weight(stones.begin(), stones.end());
        while(weight.size()>1){
            int f = weight.top();
            weight.pop();
            int s = weight.top();
            weight.pop();
            if(abs(f-s)>0){
                weight.push(abs(f-s));
            }
        }
        if(weight.empty()) return 0;
        return weight.top();

        
        
    }
};
