# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        count = 0
        curr = head
        while curr:
            count += 1
            curr = curr.next
        
        curr = head
        temp = 0

        while temp < math.ceil(count/2) - 1:
            temp += 1
            curr = curr.next
        
        list2 = curr.next
        curr.next = None
        
        # reverse list2
        prev = None
        curr2 = list2

        while curr2:
            fut = curr2.next
            curr2.next = prev
            prev = curr2
            curr2 = fut
            
        # Now merge head (first half) and prev (reversed second half)
        first = head
        second = prev

        while second:
            tmp1 = first.next
            tmp2 = second.next

            first.next = second
            second.next = tmp1

            first = tmp1
            second = tmp2

        



        