class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());
        
        unordered_map<int, int> rankMap;
        for (int i = 0; i < sortedArr.size(); i++) {
            rankMap[sortedArr[i]] = i + 1; 
        }
        
        vector<int> result;
        result.reserve(arr.size());
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }
        
        return result;
    }
};