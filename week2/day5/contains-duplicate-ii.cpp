#ifndef DUPLICATES_2
#define DUPLICATES_2
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> in_range;
        int itr = 0;
        int itr_k = 0;
        
        if (nums.size() == 0) {
            return false;
        }
        
        if (nums.size() == 1) {
            return false;
        }
        
        if (k >= nums.size()) {
            itr_k = nums.size() - 1;
        }
        else {
            itr_k = itr + k;
        }
        
        for (int i = itr + 1; i <= itr_k; i++) {
            auto i_bucket = in_range.find(nums[i]);
            if (i_bucket == in_range.end()) {
                in_range.insert(make_pair(nums[i], 1));
            }
            else {
                i_bucket->second++;
            }
        }
        
        while (itr != itr_k) {
            auto itr_bucket = in_range.find(nums[itr]);
            if (itr_bucket == in_range.end()) {
                itr++;
                auto itr_plus_bucket = in_range.find(nums[itr]);
                if (itr_plus_bucket->second > 1) {
                    itr_plus_bucket->second--;
                }
                else {
                    in_range.erase(nums[itr]);
                }
                
                if (itr_k < nums.size() - 1) {
                    itr_k++;
                    auto itr_k_plus_bucket = in_range.find(nums[itr_k]);
                    if (itr_k_plus_bucket == in_range.end()) {
                        in_range.insert(make_pair(nums[itr_k], 1));
                    }
                    else {
                        itr_k_plus_bucket->second++;
                    }
                }
            }
            else {
                return true;
            }
        }
        return false;
    }
};

#endif
