# leetcode 148 Sort List      @devottam2809   
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        nums=[]
        temp=head
        while(temp!=None):
            nums.append(temp.val)
            temp=temp.next
        nums.sort()
        dummy=ListNode(-1)
        current=dummy
        for i in nums:
            current.next=ListNode(i)
            current=current.next
        return dummy.next
