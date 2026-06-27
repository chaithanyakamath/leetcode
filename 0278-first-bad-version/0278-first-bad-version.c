// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    if(n == 1)  return 1;
    int l = 0, r = n;

    while(l<=r){
        int mid = l + (r-l)/2;
        if(isBadVersion(mid))   r = mid -1;
        else if(!isBadVersion(mid)) l = mid+1;
    }
    return l;
}