//Third fastest
var validMountainArray = function(arr) {
    if(arr.length < 3)
        return false;
    let i = 0, j = arr.length-1;
    while(i < arr.length - 2 && arr[i] < arr[i+1]){
        i++;
    }
    while(j > 0 && arr[j] < arr[j - 1]){
        j--;
    }
    console.log(`i ${i} j ${j}`)
    if(i === arr.length - 1 || j === 0)
        return false;
    return i == j;
};

//Second fastest
var validMountainArray = function(arr) {
    if(arr.length < 3) return false;
    
    let peak = 0;
    let less = 0;
    let isUp = true;
    let isPyr = true

    for(i=1;i<arr.length; i++) {
        if(arr[i] > arr[peak] && isUp) {
           peak = i
           } else if(arr[i] < arr[peak]) {
               if(isUp) {
                   isUp = false  
                   less = i
               } else if(less && arr[i] < arr[less]) {
                less = i
               isUp = false   
               } else {
                   isPyr = false
               }
          } else {
              isUp = false
              isPyr = false
          }
    }
    
    
    if(peak===0 || peak=== (arr.length -1)) {
        isPyr = false
    }
    
    return isPyr;
};

//Fastest
const validMountainArray = (arr) => {

    //default
    if(arr.length < 3) return false;

    //array is not initially increasing
    if(arr[0] >= arr[1]) return false; 

    //if this point is reached, array is increaing
    let up = true;

    //loop through array 
    for(let i = 1; i< arr.length -1; i++){
        //going down now
        if(arr[i+1] < arr[i]){
            up = false;
        }
        //going back up, so not mountain array
        if(!up && (arr[i+1] >= arr[i])){
            return false;
        }
    }
    //not mountain becuause never decreased
    if(up) return false;
    return true;
}