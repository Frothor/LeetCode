#Second fastest
def longest_mountain(a)
    if a.size < 3
        return 0
    end
    up = true
    max = 0
    count = 0
    prev = nil
    valid = false
    a.each do |m|
        if up == true
            if prev.nil?
                prev = m
                count += 1
                next
            end
            if prev < m
                prev = m
                count += 1
            elsif prev > m && count > 1
                prev = m
                count += 1
                up = false
                valid = true
            else
                prev = m
                count = 1
            end
        else
            if prev < m
                prev = m
                max = [count, max].max
                up = true
                count = 2
                valid = false
            elsif prev == m
                prev = m
                max = [count, max].max
                up = true
                count = 1
                valid = false
                
            else
                prev = m
                count += 1
            end
        end
    end
    
    if valid
        max = [max, count].max
    end
    if max < 3
        return 0
    end
    return max
            
end

#Fastest
def longest_mountain(a)
    maxMnt = 0
    i = 1
    while i < a.length
       while i < a.length && a[i-1] == a[i]
           i+= 1
       end
        up = 0
        while i < a.length && a[i-1] < a[i]
            up += 1
            i += 1
        end
        down = 0
        while i < a.length && a[i-1] > a[i]
            down += 1
            i += 1
        end
        if up > 0 && down > 0
            maxMnt = [maxMnt, up+down+1].max
        end
    end
    maxMnt
end