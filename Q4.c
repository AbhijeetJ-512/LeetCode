#include <math.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        int* tempArr = nums1;
        nums1 = nums2;
        nums2 = tempArr;
        
        int tempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tempSize;
    }

    int totalLen = nums1Size + nums2Size;
    int left = 0, right = nums1Size;
    
    while (left <= right) {
        int partitionNums1 = (left + right) / 2;
        int partitionNums2 = (totalLen + 1) / 2 - partitionNums1;
        
        int maxLeftNums1 = (partitionNums1 == 0) ? INT_MIN : nums1[partitionNums1 - 1];
        int minRightNums1 = (partitionNums1 == nums1Size) ? INT_MAX : nums1[partitionNums1];
        
        int maxLeftNums2 = (partitionNums2 == 0) ? INT_MIN : nums2[partitionNums2 - 1];
        int minRightNums2 = (partitionNums2 == nums2Size) ? INT_MAX : nums2[partitionNums2];
        
        if (maxLeftNums1 <= minRightNums2 && maxLeftNums2 <= minRightNums1) {
            if (totalLen % 2 == 0) {
                return (double)(fmax(maxLeftNums1, maxLeftNums2) + fmin(minRightNums1, minRightNums2)) / 2.0;
            } else {
                return (double)fmax(maxLeftNums1, maxLeftNums2);
            }
        } else if (maxLeftNums1 > minRightNums2) {
            right = partitionNums1 - 1;
        } else {
            left = partitionNums1 + 1;
        }
    }
    
    return -1.0; 
}