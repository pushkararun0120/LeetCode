#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;         // pointer for nums1 (last valid element)
        int j = n - 1;         // pointer for nums2 (last element)
        int k = m + n - 1;     // pointer for merged position (end of nums1)

        // Compare from the back and place the larger element at position k
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 still has elements, copy them (nums1 leftovers are already in place)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};