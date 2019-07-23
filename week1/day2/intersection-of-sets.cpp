#ifndef SOLUTION_
#define SOLUTION_

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection_list;
        unordered_set<int> seenInNums1;
        if (nums1.size() > 0) {
            seenInNums1.insert(nums1[0]);   
        }
        
        for (int i = 1; i < nums1.size(); i++) {
            if (seenInNums1.count(nums1[i]) == 0)
                seenInNums1.insert(nums1[i]);
        }
        
        
        unordered_set<int> seenInIntersection;
        for (int i = 0; i < nums2.size(); i++) {
            if (seenInNums1.count(nums2[i]) == 1) {
                if (seenInIntersection.count(nums2[i]) == 0) {
                    seenInIntersection.insert(nums2[i]);
                    intersection_list.push_back(nums2[i]);  
                }
            }
        }
        
        return intersection_list;
    }
};

#endif
