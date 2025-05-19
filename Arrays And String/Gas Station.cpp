class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
int n = gas.size();
int totalearning=accumulate(begin(gas), end(gas), 0);
int totalspend=accumulate(begin(cost), end(cost), 0);

if(totalearning<totalspend)
return -1;

int result_index=0;
int total=0;

for(int i=0;i<n;i++){
    total+=gas[i]-cost[i];
    if(total<0){
        result_index=i+1;
        total=0;
    }
}
return result_index;
    }
};