# Leetcode 92 Reverse Linked List II    @devottam2809

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    global revi
    def revi(nums,low,high):
        while(low<high):
            nums[low],nums[high]=nums[high],nums[low]
            low+=1
            high-=1
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        nums=[]
        temp=head
        while(temp!=None):
            nums.append(temp.val)
            temp=temp.next
        revi(nums,left-1,right-1)
        dummy=ListNode(-1)
        current=dummy
        for i in nums:
            current.next=ListNode(i)
            current=current.next
        return dummy.next
