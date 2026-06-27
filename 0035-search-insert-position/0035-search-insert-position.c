int searchInsert(int* nums, int numsSize, int target) {
    // int count=0;
    // for(int i=0; i<numsSize; i++){
    //     if(nums[i]<target){
    //         count++;
    //     }
    //     else{
    //         return count;
    //     }
    // }
    // return count;

    int l = 0, r = numsSize-1;
    while(l<=r){
        int mid = l + (r-l) / 2;
        if(nums[mid] == target) return mid;
        else if( target < nums[mid])    r = mid-1;
        else l = mid+1;
    }
    return l;
}