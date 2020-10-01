class RecentCounter:
    def __init__(self):
        self.calls = deque()

    def ping(self, t):
        self.calls.append(t)
        while self.calls[0] < self.calls[-1] - 3000:
            self.calls.popleft()
        return len(self.calls)

#Fastest
class RecentCounter:

    def __init__(self):
        self.queue = deque()

    def ping(self, t: int) -> int:
        queue = self.queue
        while queue and queue[0] < t - 3000:
            queue.popleft()
        queue.append(t)
        return len(queue)
        
