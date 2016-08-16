class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m==0&&n==0)
            return 0;
        int k = ((m+n+1)>>1);
        if((m+n)&1)
            return (double)findKth(nums1,0,m-1,nums2,0,n-1,k);
        else
            return ((double)findKth(nums1,0,m-1,nums2,0,n-1,k)+(double)findKth(nums1,0,m-1,nums2,0,n-1,k+1))/2.0;
    }
    
private:
    int findKth(vector<int>& nums1, const int L1, const int R1, vector<int>& nums2, const int L2, const int R2, const int k) {
        if(L1>R1) return nums2[L2+k-1];
        if(L2>R2) return nums1[L1+k-1];
        
        int mid1 = ((L1+R1)>>1);
        int mid2 = ((L2+R2)>>1);
        /*
        If nums1[mid1]<=nums2[mid2], then
        1.At least (mid1-L1)+1+(mid2-L2) numbers before nums2[mid2];
        2.At least m-(mid1-L1)-1+n-(mid2-L2)=(m+n)-((mid1-L1)+(mid2-L2)+1) numbers after nums1[mid1];
        Thus,
        If K<=(mid1-L1)+(mid2-L2)+1, the nums2 numbers within [mid2,R2] can be dropped,
        Else, the nums1 numbers within [L1,mid1] can be dropped.
        */
        if(nums1[mid1]<=nums2[mid2]) {
            if(k<=(mid1-L1)+(mid2-L2)+1)
                return findKth(nums1,L1,R1,nums2,L2,mid2-1,k);
            else
                return findKth(nums1,mid1+1,R1,nums2,L2,R2,k-(mid1-L1)-1);
        }
        else {
            if(k<=(mid1-L1)+(mid2-L2)+1)
                return findKth(nums1,L1,mid1-1,nums2,L2,R2,k);
            else
                return findKth(nums1,L1,R1,nums2,mid2+1,R2,k-(mid2-L2)-1);
        }
    }
};
