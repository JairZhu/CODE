//基于堆的优先队列
public class MaxPQ<Key extends Comparable<Key>>
{
    private Key[] pq;
    private int N = 0;
    public MaxPQ(int maxN)
    { pq = (Key[]) new Comparable[maxN + 1]; }
    public boolean isEmpty() { return N == 0; }
    public int size() { return N; }
    private void swim(int k)                //由下而上的堆有序化（上浮）
    {
        while (k > 1 && less(k / 2, k))
        {
            exch(k / 2, k);
            k = k / 2;
        }
    }
    private void sink(int k)                //由上而下的堆有序化（下沉）
    {
        while (2 * k <= N)
        {
            int j = 2 * k;
            if (j < N && less(j, j + 1)) j++;
            if (!less(k, j)) break;
            exch(k, j);
            k = j;
        }
    }
    public void insert(Key v) 
    {
        pq[++N] = v;
        swim(N);
    }
    public Key delMax() 
    {
        Key max = pq[1];
        exch(1, N--);
        pq[N + 1] = null;
        sink(1);
        return max;
    }
}