# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        ans = None
        if list1 == None and list2 == None:
            return ans
        elif list1 == None and list2:
            return list2
        elif list2 == None and list1:
            return list1

        ans= list1 if list2.val >= list1.val else list2
        curr = ans

        if list2.val >= list1.val:
            list1 = list1.next
        else:
            list2 = list2.next
        
        while list1 and list2:
            if list2.val >= list1.val:
                curr.next = list1
                list1 = list1.next
            else:
                curr.next = list2
                list2 = list2.next
            curr = curr.next
                
        
        while list1:
            curr.next = list1
            list1 = list1.next
            curr = curr.next

        while list2:
            curr.next = list2
            list2 = list2.next
            curr = curr.next
        
        return ans