class Solution {
public:
    int createKey(string &s) {
        int mult;
        int sum;
        for (int i = 0; i < s.length(); i++) {
            mult *= (int(s[i]));
            sum += (int(s[i]));
        }
        return mult + add;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<string>> map;
        for (int i = 0; i < strs.size(); i++) {
            
            if (map.find(createKey(strs[i])) != map.end()) {
                map.find(createKey(strs[i]))->second.push_back(strs[i]);
            }
            else {
                vector<string> newList;
                newList.push_back(strs[i]);
                pair<int, vector<string>> newItem(createKey(strs[i]), newList);
                map.insert(newItem);
            }
        }
    }
};
