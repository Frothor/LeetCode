#Third fastest
# 给一个有乘除法，加减的算式，给出计算结果

# 思路
# 1. we can treat different characters differently
# 2. for number, we can just add to the number we have so far
# 3. and for operators, we can get the result based on last operator and then push the result into the stack
# 4. finally we can sum the result from the stack and that should be the answer

# 如果有括号
# 5. for open bracket, we can do recursion from this index
# 6. for close bracket, we should return the result to the level above


class Calculator
    @@numbers = (0..9).map { |num| num.to_s }
    def initialize(expression)
      @expression = (expression + '+').chars
    end
  
    def evaluate
      number = 0
      stack = []
      operator = '+'
      until @expression.empty?
        char = @expression.shift
        next if char == ' '
  
        # if it;s just a regular number
        if @@numbers.include?(char)
          number = number * 10 + char.to_i
          next
        end
  
        # =begin TODO recursion: one level down
        # if char == '('
        #   number = evaluate() # TODO
        #   next
        # end
        # =end TODO
  
        # conclude the window if not a digit
        if operator == '+'
          stack.push(number)
        elsif operator == '-'
          stack.push(-1 * number)
        elsif operator == '*'
          stack.push(stack.pop * number)
        elsif operator == '/'
          divisor = stack.pop
          stack.push(
            (divisor >= 0 ? 1 : -1) * (divisor.abs / number)
          )
        end
        operator = char
        number = 0
  
        # break and return back to the level above
        # break if char == ')' # TODO
      end
      stack.sum
    end
  end
  
  def calculate(s)
    Calculator.new(s).evaluate
  end

#Second fastest
def evaluate(left, right, op)
    case op
        when '+'
            return left + right
        when '-'
            return left - right
        when '*'
            return left * right
        when '/'
            return left / right
        else
            return 0
    end
end

def calculate(s)
    digits = '0123456789'.chars
    operations = '+-*/'.chars
    result = 0
    nums = []
    ops = []
    num = 0
    s.chars().each do |c|
        next if c == ' '
        if digits.include?(c)
            num = num * 10 + c.to_i
        else operations.include?(c)
            nums << num
            num = 0
            if ops.length > 0
                if ops[-1] == '*' || ops[-1] == '/'
                    right = nums.pop rescue 1
                    left = nums.pop rescue 1
                    op = ops.pop
                    nums << evaluate(left, right, op)
                end
            end
            ops << c
        end
    end

    nums << num
    if ops.length > 0
        if ops[-1] == '*' || ops[-1] == '/'
            right = nums.pop rescue 1
            left = nums.pop rescue 1
            op = ops.pop
            nums << evaluate(left, right, op)
        end
    end
    
    index = 0
    val = nums[index]
    ops.each do |op|
        index += 1
        val = evaluate(val, nums[index], op)
    end
    
    val
end

#Fastest
def calculate(s)
    num = 0
    res = 0
    prod = 1
    inverse = false
    sign = 1
    s.chars.each do |c|
        next if c == ' '
        if c == '+'
            if inverse
                prod /= num
            else
                prod *= num
            end
            res += prod * sign
            num = 0
            sign = 1
            prod = 1
            inverse = false
        elsif c == '-'
            if inverse
                prod /= num
            else
                prod *= num
            end
            res += prod * sign
            num = 0
            sign = -1
            prod = 1
            inverse = false
        elsif c == '*'
            if inverse
                prod /= num
            else
                prod *= num
            end
            inverse = false
            num = 0
        elsif c == '/'
            if inverse
                prod /= num
            else
                prod *= num
            end
            num = 0
            inverse = true
        else
            num = num * 10 + c.to_i
        end
    end
    if inverse
        prod /= num
    else
        prod *= num
    end
    res += prod * sign
    res
end