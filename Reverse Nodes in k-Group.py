# Leetcode 25   Reverse Nodes in k-Group      @devottam2809


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    global rev
    def rev(nums,low,high):
        while(low<high):
            nums[low],nums[high]=nums[high],nums[low]
            low+=1
            high-=1
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        nums=[]
        temp=head
        while(temp!=None):
            nums.append(temp.val)
            temp=temp.next
        
        n=len(nums)
        i=0
        j=k
        while(j<=n):
            rev(nums,i,j-1)
            i+=k
            j+=k
        
        dummy=ListNode(-1)
        current=dummy
        for i in nums:
            current.next=ListNode(i)
            current=current.next
        return dummy.next
