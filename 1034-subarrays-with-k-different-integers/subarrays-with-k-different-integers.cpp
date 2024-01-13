class Solution {
public:
    int atMostK(vector<int>& nums, int k){
        int n=nums.size();
        unordered_map<int, int> mp;
        int i=0, j=0, ans=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k)-atMostK(nums, k-1);
    }
};