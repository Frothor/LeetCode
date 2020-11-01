const getDecimalValue = head => {
    let val = 0;
    while(head)
        {
            val*=2;
            val+=head.val;
            head = head.next;
        }
    return val;
};

//Third fastest
var getDecimalValue = function(head) {
    let res = 0;
    let node = head;
    
    while (node) {
        res = res * 2 + node.val;
        node = node.next;
    }
    return res
};

//Second fastest
var getDecimalValue = function(head) {
    let result = 0;
    let tmp = head;
    let counter = 0;
    
    while(tmp !== null) {
        counter++;
        tmp = tmp.next;
    }
    
    tmp = head;
    let i = 0;
    
    while(tmp !== null) {
        result += tmp.val * Math.pow(2,counter - i - 1);
        tmp = tmp.next;
        i++;
    }
    return result;
};

//Fastest
var getDecimalValue = function(head)
{
    let digitStack = new Array();
    
    for (let node = head; node != null; node = node.next)
    {
        digitStack.push(node.val);
    }
    
    let digitCount = digitStack.length;
    let result = 0;
    let multiplier = 1;
    
    for (let i = 0; i < digitCount; ++i)
    {
        if (digitStack.pop() == 1)
        {
            result += multiplier;
        }
        
        multiplier *= 2;
    }
    
    return result;
};