class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest_cons_seq = 0;

        for (int num : nums) {
            if (num_set.find(num - 1) != num_set.end()) {
                continue;
            }
            
            int cons_seq = 0;
            int current_num = num;
            while (num_set.find(current_num) != num_set.end()) {
                current_num++;
                cons_seq++;
            }

            longest_cons_seq = max(longest_cons_seq, cons_seq);
        }

        return longest_cons_seq;     
    }
};
