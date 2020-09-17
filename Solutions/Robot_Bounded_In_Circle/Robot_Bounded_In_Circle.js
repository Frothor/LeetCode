//Most common
/**
 * @param {string} instructions
 * @return {boolean}
 */
var isRobotBounded = function(instructions) {
    let ins = new Array(4).fill(instructions)
    ins = ins.join('')
    let way = 0
    const point = [0, 0]
    for (let i of ins) {
        if (i === 'G') {
            if (way === 0) {
                point[1]++
            } else if (way === 1) {
                point[0]++
            } else if (way === 2) {
                point[1]--
            } else if (way === 3) {
                point[0]--
            }
        }
        
        if (i === 'L') {
            if (way === 0) {
                way = 3
            } else {
                way--
            }
        }
        
        if (i === 'R') {
            if (way === 3) {
                way = 0
            } else {
                way++
            }
        }
    }
    
    if (point[0] === 0 && point[1] === 0) return true
    return false
};

//Fastest
var isRobotBounded = function(instructions) {
    let steps = [
        [-1,0],
        [0,1],
        [1,0],
        [0,-1]
    ];
    let x = y = 0;
    
    let currStep = 1;
    let turn = (direction) =>{
        if(direction === "L") currStep--;
        else if(direction === "R") currStep++;
        else if(direction === "G") {
            x += steps[currStep][0];
            y += steps[currStep][1];
        }
        if(currStep < 0) currStep = 3;
        if(currStep === 4) currStep = 0;
    }
    
    
    for(let i=0; i<instructions.length*4; i++){
        turn(instructions[i]);
    }
	// I was stucked at the last return. The following line might be the key line for this problem.
	// as lone as the robot is at (0,0) or not going north, it should be true.
    return (currStep !== 1) || (x ===0 && y===0);
};