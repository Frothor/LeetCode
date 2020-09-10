//One pass solution
var getHint = function(secret, guess) {
    let bull = 0;
    let cow = 0;
    const numCount = new Array(10).fill(0);
    
    for(let i = 0; i < secret.length; i++) {
        if(secret[i] === guess[i]) bull++;
        else {
            numCount[+secret[i]]++;
            if(numCount[+secret[i]] <= 0) cow++;
            numCount[+guess[i]]--;
            if(numCount[+guess[i]] >= 0) cow++;
        }
    }
    return `${bull}A${cow}B`
};

//Fastest
const getHint = (secret, guess) => {
    let bulls = 0, cows = 0, numbers = new Array(10).fill(0);
    
    for (let i = 0; i<secret.length; i++) {
        if (secret.charAt(i) == guess.charAt(i)) bulls++;
        else {
            if (numbers[+secret.charAt(i)]++ < 0) cows++;
            if (numbers[+guess.charAt(i)]-- > 0) cows++;
        }
    }
    return bulls + "A" + cows + "B";
};