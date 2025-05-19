class Solution {
public:
    int hIndex(vector<int>& cit) {
        sort(cit.rbegin(),cit.rend());
        int n=cit.size();
        int h=0;

        for(int i=0;i<n;i++){
            if(cit[i]>=i+1){
                h=i+1;
            }else{
                break;
            }
        }
        return h;
    }

   
};