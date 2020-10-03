/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function(nums, k) {
    let sol = 0;
    const v = {};
    
    if (k < 0) return 0;

    for (let x of nums) {
             
        // New number found, increase sol if v+k or v-k complements exist
        if (!v[x]) {
            sol += !!v[x + k] + !!v[x - k]; 
            v[x] = 1;
        }
      
        // K = 0 special case
        // Existing number, check if number was not already done, if yes, mark it as done
        else if(k === 0 && v[x] !== -1) {
            v[x] = -1;
            sol++;
        }
        
    }
    
    return sol;
};