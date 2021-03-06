//自顶向下的归并排序
public class Merge
{
    private static Comparable[] aux;   //辅助数组
    public static void sort(Comparable[] a)
    {
        aux = new Comparable[a.length];//一次性分配空间
        sort(a, 0, a.length - 1);
    }
    public static void merge(Comparable[] a, int lo, int mid, int hi)
    {
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) 
            aux[k] = a[k];
        for (int k = lo; k <= hi; k++)
            if (i > mid) a[k] = aux[j++];
            else if (j > hi) a[k] = aux[i++];
            else if (aux[i] < aux[j]) a[k] = aux[i++];
            else a[k] = aux[j++];
    }
    private static void sort(Comparable[] a, int lo, int hi)
    {
        if (hi <= lo) return;
        int mid = lo + (hi - lo) / 2;
        sort(a, lo, mid);               //将左半边排序
        sort(a, mid + 1, hi);           //将右半边排序
        if (a[mid] > a[mid + 1])
            merge(a, lo, mid, hi);          //归并结果
    }
}