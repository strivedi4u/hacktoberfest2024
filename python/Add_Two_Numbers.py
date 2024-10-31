
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        s=""
        head1=l1
        while head1 is not None:
            s=s+str(head1.val)
            head1=head1.next
        s2=""
        head2=l2
        while head2 is not None:
            s2=s2+str(head2.val)
            head2=head2.next
        
            
        n=int(s[::-1])+int(s2[::-1])
        j=str(n)
        new=None
        for i in j[::-1]:
            t=ListNode(int(i))
            if(new==None):
                new=t
                newhead=new
            else:
                newhead.next=t
                newhead=t
        return new