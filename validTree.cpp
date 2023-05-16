public class Solution {
		/**
		* @param n: An integer
		* @param edges: a list of undirected edges
		* @return: true if it's a valid tree, or false
		*/
		public boolean validTree(int n, int[][] edges) {
			int numOfEdge = edges.length;
// 判断是否为 (n - 1) 条边
			if (numOfEdge != n - 1) {
				return false;
			}
// adjacent[i][j]里存i与j是否相邻
			int[][] adjacent = new int[n + 2][n + 2];
			for (int i = 0; i < numOfEdge; i++) {
				int u = edges[i][0], v = edges[i][1];
				adjacent[u][v] = adjacent[v][u] = 1;
			}
// visit[i]记录i是否被访问
			int[] visit = new int[n + 5];
// 0作为根结点，开始向下遍历
			visit[0] = 1;
			int root = 0, numOfVisited = 1;
			Queue<Integer> q = new LinkedList<Integer>();
			q.add(root);
			while (!q.isEmpty()) {
				root = q.poll();
				for (int i = 0; i < n; i++) {
					if (adjacent[root][i] != 1) {
						continue;
					}
// 如果相邻且没有被访问过，说明是儿子，加入队列
					if (visit[i] == 0) {
						visit[i] = 1;
						numOfVisited++;
						q.add(i);
					}
				}
			}
			if (numOfVisited == n) {
				return true;
			}
			return false;
		}
}