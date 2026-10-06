class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                // Target lies in the sorted left half
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // Right half is sorted
            else {

                // Target lies in the sorted right half
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};