# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        count = 0

        
        curr = head
        while curr:
            count += 1
            curr = curr.next
        
        if count == 1:
            return None
        elif n == count:
            return head.next
        
        curr = head
        t = 1
        while t < count - n:
            t += 1
            curr = curr.next
        
        if curr.next:
            curr.next = curr.next.next
        else:
            curr.next = None
        
        return head
