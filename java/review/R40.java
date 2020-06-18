package review;

public class R40 {
    public static int partition(int[] arr,int p,int q){
	    int pe = arr[q];
		int i = p - 1;
		for (int j = p;j < q;j++){
			if (arr[j] <= pe){
				i++;
				int d = arr[j];
				arr[j] = arr[i];
				arr[i] = d;
			}
		}
		arr[q] = arr[i+1];
		arr[i+1] = pe;
		return i + 1;
    }
    
    public static int randomPartition(int[] arr,int p,int q){
	    int r = p + (int)((q - p)*Math.random());
		int temp = arr[q];
		arr[q] = arr[r];
		arr[r] = temp;
		return partition(arr,p,q);
    }
    
    public static int circleSelected(int[] arr,int p,int r,int i){
	    if (p == r){
			return arr[p];
	    }
		int q = randomPartition(arr,p,r);
		int k = q - p + 1;                       //计算 arr[p,..,q]元素个数
		while (k != i){                          //恰好前一部分有i个元素时，那么这部分arr[q] 为第i元素
			if (k < i){                          
				i = i - k;                       //当前一部分不够时，但前一部分已经有了前k个元素，那么只需要找第i-k即可
				p = q + 1;
			}else{                               //当前一部分比i要多时
			    r = q - 1;
			}
            q = randomPartition(arr,p,r);
			k = q - p + 1;
		}
		return arr[q];
	}
    
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k <= 0) {
            return new int[]{};
        }
        int nk = circleSelected(arr, 0, arr.length - 1, k);
        int[] res = new int[k];
        int i = 0;
        for (int a : arr) {
            if (a <= nk) {
                res[i] = a;
            }
            ++i;
            if (i >= k) {
                break;
            }
        }
        return res;
    }
}