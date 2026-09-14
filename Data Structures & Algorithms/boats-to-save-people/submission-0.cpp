class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int left = 0;
        int right = static_cast<int>(people.size()) - 1;
        int boat = 0;
        int boat_count = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            boat_count++;
        }

        return boat_count;
    }
};