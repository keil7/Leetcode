class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0) {
            nums1 = nums2;
            return;
        }
        if(n==0)
            return;
            
        //nums1.resize(m+n);
        int index1 = m-1;
        int index2 = n-1;
        for(int i=m+n-1;index1>=0&&index2>=0;) {
            while(nums1[index1]<=nums2[index2]&&index2>=0)
                nums1[i--] = nums2[index2--];
            while(nums1[index1]>nums2[index2]&&index1>=0)
                nums1[i--] = nums1[index1--];
        }
        while(index2>=0) {
            nums1[index2] = nums2[index2];
            --index2;
        }
    }
};
