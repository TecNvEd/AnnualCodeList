public class Solution {
		/**
		* @param n: An integer
		* @param edges: a list of undirected edges
		* @return: true if it's a valid tree, or false
		*/
		public boolean validTree(int n, int[][] edges) {
			int numOfEdge = edges.length;
// �ж��Ƿ�Ϊ (n - 1) ����
			if (numOfEdge != n - 1) {
				return false;
			}
// adjacent[i][j]���i��j�Ƿ�����
			int[][] adjacent = new int[n + 2][n + 2];
			for (int i = 0; i < numOfEdge; i++) {
				int u = edges[i][0], v = edges[i][1];
				adjacent[u][v] = adjacent[v][u] = 1;
			}
// visit[i]��¼i�Ƿ񱻷���
			int[] visit = new int[n + 5];
// 0��Ϊ����㣬��ʼ���±���
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
// ���������û�б����ʹ���˵���Ƕ��ӣ��������
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