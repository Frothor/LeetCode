#Second fastest
#https://leetcode.com/problems/linked-list-random-node/discuss/957266/Ruby-solution
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
class Solution

=begin
    @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
    :type head: ListNode
=end
    def initialize(head)
        @arr = []
        while head!=nil
            @arr<<head.val
            head=head.next
        end
        @count = @arr.length
    end


=begin
    Returns a random node's value.
    :rtype: Integer
=end
    def get_random()
        @arr[rand(@count)]
    end

end

# Your Solution object will be instantiated and called as such:
# obj = Solution.new(head)
# param_1 = obj.get_random()

#Another
class Solution

    =begin
        @param head The linked list's head.
            Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
    =end
        def initialize(head)
            @list = []
            while head && head.val
                @list << head.val
                head = head.next
            end
        end
    
    
    =begin
        Returns a random node's value.
        :rtype: Integer
    =end
        def get_random()
            @list.sample
        end
    
    
    end

#Fastest
class Solution
    attr_reader :head, :arr
    
    def initialize(head)
      @head = head
      @arr = []
      mover = head
      while mover do
        @arr << mover.val
        mover = mover.next
      end
    end
  
    def get_random()
      return @arr.sample
      mover = head
      scope = 1
      chosen = nil
      
      while mover do
        chosen = mover.val if rand < (1.0/scope)
        scope += 1
        mover = mover.next
      end
      
      chosen
    end
  end