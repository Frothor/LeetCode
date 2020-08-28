var fizzBuzz = function(n) {
    return _.times(n, x => {
        x = x + 1;
        let str = '';

        if (x % 3 === 0) str += 'Fizz';
        if (x % 5 === 0) str += 'Buzz';

        return str || String(x);
    })
};

var fizzBuzz = function(n) {
    // create a result array of n length
    // loop from 1 to n
        // check if i is divided by both 3 & 5- put "FizzBuzz"
        // else if i is divide by 3 put "Fizz"
        // else if i is divide by 5 put "Buzz"
        // else put i (convert to string) in the array
    
    const res = new Array(n);
    for (let i = 1; i <= n ; i++){
        if(i % 15 === 0) res[i-1] = 'FizzBuzz';
        else if(i % 3 === 0) res[i-1] = 'Fizz';
        else if(i % 5 === 0) res[i-1] = 'Buzz';
        else res[i-1] = i.toString();
    }
    return res;
};