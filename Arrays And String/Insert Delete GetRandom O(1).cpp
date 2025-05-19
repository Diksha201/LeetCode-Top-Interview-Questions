class RandomizedSet {
public:
vector<int>vec;
unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
        return false;

        vec.push_back(val);
        mp[val]=vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
        return false;
        int idx=mp[val];
        int lastEle=vec.back();
        vec.back()=val;

        vec[idx]=lastEle;
        mp[lastEle]=idx;

        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n=vec.size();
        int randomIndex=rand()%n;
        return vec[randomIndex];
    }
};