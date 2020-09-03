from queue import PriorityQueue as pq
def solution(board):
    SIZE = len(board)
    OPEN, WALL = range(2)
    START1 = (0, 0, 0, 0) #cost, x, y, d
    START2 = (0, 0, 0, 1)
    END_POINT = (SIZE-1, SIZE-1)
    DELTAS = ((0, 1), (1, 0), (0, -1), (-1, 0)) #0, 1, 2, 3
    
    q = pq()
    q.put(START1)
    q.put(START2)
    visited = set()
    visited.add(START1)
    visited.add(START2)
    
    def _is_in_range(x, y):
        return 0 <= x < SIZE and 0 <= y < SIZE
    
    def _is_open(x, y):
        return board[x][y] == OPEN
    
    def _is_ok(x, y):
        return _is_in_range(x, y) and _is_open(x, y)
    
    def _yield_moves(cost, x, y, d):
        for i in [d, (d+1)%4, (d+3)%4]:
            dx, dy = DELTAS[i]        
            nx, ny = x + dx, y + dy
            if _is_ok(nx, ny) and _is_ok(nx, ny):
                if i == d:
                    yield (cost+100, nx, ny, i)
                else:
                    yield (cost+600, nx, ny, i)
                    
    while q.queue:
        cost, x, y, d = q.get()
        if (x, y) == END_POINT:
                return cost
        for next_road in _yield_moves(cost, x, y, d):
            if next_road not in visited:
                q.put(next_road)
                visited.add(next_road)
            
        
    return


print(solution([[0,0,0],[0,0,0],[0,0,0]]))
