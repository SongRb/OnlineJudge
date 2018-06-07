class Solution {
public:
    int i = 0, j=0;
    int cnt=0;
    
    int getValue(const vector<int>& nums1, const vector<int>& nums2, int index)
    {
        int length1 = nums1.size();
        int length2 = nums2.size();
        while(true)
        {
            while(i<length1 && (j==length2 || nums1[i]<nums2[j]))
            {
                if(cnt==index) return nums1[i];
                i++;
                cnt++;
            }
            while(j<length2 && (i==length1 || nums1[i]>=nums2[j]))
            {
                if(cnt==index) return nums2[j];
                j++;
                cnt++;
            }
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        int totalLength = length1+length2;
        if(totalLength%2==0)
        {
            return (getValue(nums1, nums2, totalLength/2-1)+getValue(nums1, nums2, totalLength/2))/2.0;
        }
        else
        {
            return getValue(nums1, nums2, totalLength/2);
        }
    }
};