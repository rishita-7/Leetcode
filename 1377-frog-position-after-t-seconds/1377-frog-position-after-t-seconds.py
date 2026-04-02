class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        visited = [False] * (n + 1)
        q = deque([(1, 1.0, 0)])  # (node, probability, time)
        visited[1] = True
        
        while q:
            node, prob, time = q.popleft()
            
            if time == t:
                if node == target:
                    return prob
                continue

            # Find unvisited neighbors
            children = [nei for nei in graph[node] if not visited[nei]]
            if not children:
                if node == target:
                    return prob
                continue
            
            for child in children:
                visited[child] = True
                q.append((child, prob / len(children), time + 1))
        
        return 0.0