public class BreadthFirstPaths
{
    private boolean[] marked;
    private int[] edgeTo;
    private final int s;            //起点

    public BreadthFirstPaths(Graph G, int s)
    {
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        this.s = s;
        bfs(G, s);
    }

    private void bfs(Graph G, int s) 
    {
        Queue<INTEGER> queue = new Queue<INTEGER>();
        marked[s] = true;           //标记起点
        queue.enqueue(s);           //加入列表 
        while (!queue.isEmpty())
        {
            int v = queue.dequeue();//从队列中删除去下一个顶点
            for (int w : G.adj(v))  
                if (!marked[w])     //对于每个未被标记的相邻的顶点
                {
                    edgeTo[w] = v;  //保存最短路径的最后一条边标记它，因为最短路径已知并将它添加到队列中
                    marked[w] = true;
                    queue.enqueue(w);
                }
        }
    }

    public boolean hasPathTo(int v)
    { return marked[v]; }

    public Iterable<Integer> pathTo(int v) 
    {
        if (!hasPathTo(v)) return null;
        Stack<Integer> path = new Stack<Integer>();
        for (int x = v; x != s; x = edgeTo[x])
            path.push(x);
        path.push(s);
        return path;
    }
}