import java.util.*;

class SegmentTree {
    int segarr[];

    public SegmentTree(int[] arr) {
        segarr = new int[4 * arr.length+1];
        buildTree(arr, 0, 0, arr.length - 1);
    }

    public void buildTree(int[] arr, int idx, int l, int r) {
        if (l == r) {
            segarr[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        buildTree(arr, 2 * idx + 1, l, mid);
        buildTree(arr, 2 * idx + 2, mid + 1, r);
        segarr[idx] = segarr[2 * idx + 1] + segarr[2 * idx + 2];
        return;
    }

    
    public int query(int q1, int q2, int n) {
        return getSum(0, n - 1, q1, q2, 0);
    }

    private int getSum(int st, int end, int q1, int q2, int idx) {
        // If the query range matches the segment range
        if (q1 <= st && q2 >= end) {
            return segarr[idx];
        }

        // If the query range is outside the segment range
        if (q2 < st || q1 > end) {
            return 0;
        }

        int mid = (st + end) / 2;
        return getSum(st, mid, q1, Math.min(q2, mid), 2 * idx + 1) +
               getSum(mid + 1, end, Math.max(q1, mid + 1), q2, 2 * idx + 2);
    }

    public void updateidx(int idx, int val, int n){
        updatefunc(idx, val, 0, n-1, 0);
    }
    private void updatefunc(int idx, int val, int st, int end, int cidx){
        if(st==end){
            if(st==idx){
                segarr[cidx]=val;
                return;
            }
            return;
        }
        int mid=(st+end)/2;
        if(idx<=mid){
            updatefunc(idx, val, st, mid, 2*cidx+1);
        }
        else{
            updatefunc(idx, val,mid+1,end, 2*cidx+2);
        }
        segarr[cidx]= segarr[2*cidx+1]+segarr[2*cidx+2];
    }
}

class implementation {
    public static void main(String[] args) {
        int arr[] = new int[]{5, 6, 1, 8, 3, 4, 7, 9, -1, 7};
        SegmentTree t1 = new SegmentTree(arr);
        for (int i : t1.segarr) {
            System.out.print(i+" ");
        }
System.out.println();
        System.out.println(t1.query(2,8, arr.length));
    }
}
