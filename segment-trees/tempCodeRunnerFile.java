import java.util.*;

class SegmentTree{
    int segarr[];
    public SegmentTree(int [] arr){
        segarr= new int[2*arr.length];
        buildTree(arr,0,0,arr.length-1);
    }

    public void buildTree(int[] arr, int idx, int l, int r){
        if(l==r){
            segarr[idx]=arr[l];
            return ;
        }
        int mid= (l+r)/2;
        buildTree(arr, 2*idx+1, l, mid);
        buildTree(arr, 2*idx+2, mid+1, r);
        segarr[idx]= segarr[2*idx+1]+ segarr[2*idx+2];
        return;
    }
}

 class implementation {
    
    public static void main(String[] args) {
        int arr[]= new int[]{5,6,1,8,3,4};
        SegmentTree t1= new SegmentTree(arr);
        for(int i: t1.segarr){
            System.out.println(i);
        }

    }

}
