# Rotate List Leetcode 61   @devottam2809
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
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if(head==None):
            return head
        nums=[]
        temp=head
        while(temp!=None):
            nums.append(temp.val)
            temp=temp.next

        n=len(nums)
        if(k!=0):
            k=k%n
        revi(nums,0,n-k-1)
        revi(nums,n-k,n-1)
        revi(nums,0,n-1)
        # print(nums)
        dummy=ListNode(-1)
        current=dummy
        for i in nums:
            current.next=ListNode(i)
            current=current.next
        return dummy.next
