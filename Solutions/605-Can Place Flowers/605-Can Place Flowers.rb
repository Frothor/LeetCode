#Third fastest
def can_place_flowers(flowerbed, n)
    if flowerbed.length < 2 * (n - 1) + 1
        return false
    end
    
    count = 0
    if flowerbed[0] == 0 && flowerbed[1] == 0
        count += 1
        flowerbed[0] = 1
    end
    
    if flowerbed[flowerbed.length - 2] == 0 && flowerbed[flowerbed.length - 1] == 0
        count += 1
        flowerbed[flowerbed.length - 1] = 1
    end
    
    for i in 1..(flowerbed.length - 2)
        if flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0
            count += 1
            flowerbed[i] = 1
        end
    end
    return count >= n
end

#Second fastest
def can_place_flowers(flowerbed, n)
    i = 0
    count = 0
    
    while i < flowerbed.length
        if flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)
            flowerbed[i] == 1
            i += 1
            count += 1
        end
        
        if count >= n
            return true
        end
        i += 1
        
    end
    
    false
end

#Fastest
def can_place_flowers(flowerbed, n)
    return true if n == 0 
    flowerbed << 0 
    flowerbed.unshift(0)
    count = 0 
    
    (1...flowerbed.size - 1).each do |ind|
        if flowerbed[ind] == 0 && flowerbed[ind - 1] == 0 && flowerbed[ind + 1] == 0
            flowerbed[ind] = 1 
            count += 1 
        end
        
        return true if count == n 
    end 
    
    return false 
end