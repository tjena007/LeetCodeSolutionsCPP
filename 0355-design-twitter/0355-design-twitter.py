import heapq

class Twitter:

    def __init__(self):
        self.time = 0
        self.users = {}      # followerId -> {followeeId: 1}
        self.userPosts = {}  # userId -> list of (time, tweetId)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.time += 1
        self.userPosts.setdefault(userId, []).append((self.time, tweetId))

    def getNewsFeed(self, userId: int) -> list[int]:
        maxHeap = []

        # Add own tweets
        for time, tweetId in self.userPosts.get(userId, []):
            heapq.heappush(maxHeap, (-time, tweetId))

        # Add followee tweets
        for followee in self.users.get(userId, {}):
            for time, tweetId in self.userPosts.get(followee, []):
                heapq.heappush(maxHeap, (-time, tweetId))

        # Get top 10 tweets
        res = []
        while maxHeap and len(res) < 10:
            _, tweetId = heapq.heappop(maxHeap)
            res.append(tweetId)

        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId == followeeId:  # can't follow self
            return
        self.users.setdefault(followerId, {})[followeeId] = 1

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId in self.users and followeeId in self.users[followerId]:
            del self.users[followerId][followeeId]
