from collections import deque
from typing import Optional

class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None

        parent = {}  
        deepest_nodes = []
        max_depth = 0
        
        q = deque([(root, 0)])
        parent[root] = None
        
        while q:
            node, depth = q.popleft()
            
            if depth > max_depth:
                max_depth = depth
                deepest_nodes = [node]
            elif depth == max_depth:
                deepest_nodes.append(node)
            
            if node.left:
                parent[node.left] = node
                q.append((node.left, depth + 1))
            if node.right:
                parent[node.right] = node
                q.append((node.right, depth + 1))
        

        if len(deepest_nodes) == 1:
            return deepest_nodes[0]
        

        def get_ancestors(node):
            ancestors = []
            while node:
                ancestors.append(node)
                node = parent[node]
            ancestors.reverse()  # Reverse in place
            return ancestors
        

        ancestors_list = [get_ancestors(node) for node in deepest_nodes]
        

        lca = None
        min_length = min(len(ancestors) for ancestors in ancestors_list)
        
        for i in range(min_length):
            current = ancestors_list[0][i]
            for ancestors in ancestors_list[1:]:
                if ancestors[i] != current:
                    return lca
            lca = current
        
        return lca