/**
 /**
 * @param {number[][]} rects
 */
var Solution = function(rects) {
    this.rects = rects;
    this.map = {};
    this.sum = 0;
    // we put in the map the number of points that belong to each rect
    for(let i in rects) {
        const rect = rects[i];
        // the number of points can be picked in this rectangle
        this.sum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
        this.map[this.sum] = i;
    }
    this.keys = Object.keys(this.map);
};

/**
 * @return {number[]}
 */
Solution.prototype.pick = function() {
    // random point pick between [1, this.sum]
    const randomPointPick = Math.floor(Math.random() * this.sum) + 1;
    
    // we look for the randomPointPick in the keys of the map
    let pointInMap;
    // the keys exists in map
    if(this.map[randomPointPick]) pointInMap = randomPointPick;
    // the key is the first in the map (we do this check before doing binary search because its out of boundery)
    else if(randomPointPick < this.keys[0]) pointInMap = this.keys[0];
    let high = this.keys.length;
    let low = 1;
    // binary search to find the closest key that bigger than randomPointPick
    while(low <= high && !pointInMap) {
        const mid = Math.floor((low + (high-low)/2));
        if(randomPointPick > this.keys[mid-1] && randomPointPick < this.keys[mid]) {
            pointInMap = this.keys[mid];
            break;
        } else if (randomPointPick > this.keys[mid]){
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    
    // we have the point, now we can get which rect belong to that point
    const pointInRects = this.map[pointInMap];
    const chosen = this.rects[pointInRects];
    const rightX = chosen[2];
    const leftX = chosen[0];
    const topY = chosen[3];
    const bottomY = chosen[1];
    const pickX = Math.floor(Math.random() * (rightX-leftX+1)) + leftX;
    const pickY = Math.floor(Math.random() * (topY-bottomY+1)) + bottomY;
    return [pickX, pickY]
};


//Another. Image in images: Example-of-alias-method_js_second_solution.png
//Original post: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/discuss/805452/Javascript-O(n)-initiation-O(1)-picking-using-Alias-Method
/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(rects)
 * var param_1 = obj.pick()
 */

var Solution = function(rects) {
    // Imagine we put the boxes into a 2D pool and pick one. Then the bigger box will more likely to be seen and picked
    // So first we initialize the pool with the area of the boxes
    let totalArea = 0;
    this.boxes = rects.map(([x1, y1, x2, y2], index, area) => (
      totalArea += area = (x2 - x1 + 1) * (y2 - y1 + 1),
      { area, index, x1, y1, x2, y2 }
    ));
    // Alias method says that, for example you have n boxes, and n rooms with can contain exactly the average area of the boxes,
    // you can distribute the content of the boxes into the rooms such that each room contains only content of 2 type of boxes.
    // So the idea is putting each box into each room. Then some box will be larger than the room, and some will be smaller
    // You can then split the larger box and put into the room which contains the smaller box
    // So now let's classify the boxes base on if it's larger or smaller than the room size
    const avgArea = this.avg = totalArea / rects.length;
    const smallers = this.boxes.filter(box => box.area < avgArea);
    const largers = this.boxes.filter(box => box.area > avgArea);
    while (smallers.length !== 0 && largers.length !== 0) {
      const smaller = smallers.shift();
      const larger = largers[0];
      smaller.added = larger.index;
      larger.area -= avgArea - smaller.area;
      // After splitting the larger box, calling A for example, and put into the room of the smaller box, that room is now full, and we no longer care about it
      // About the box A, if it is now still bigger than the room capacity, keep it in the "largers" stack to work with later
      // If it is now fit into its room, forget about it
      // If it becomes smaller for a typical room, we put it into the "smallers" stack to find it a new "larger boxie"
      larger.area <= avgArea && (
        largers.shift(),
        larger.area < avgArea && (smallers[smallers.length] = larger)
      );
    }
    this.pick = function() {
      // Now we just need to pick a random room
      const box = this.boxes[Math.random() * this.boxes.length | 0];
      // And then pick 1 of the 2 boxes in that room, based on their area as above
      const { x1, y1, x2, y2 } = Math.random() * this.avg > box.area ? this.boxes[box.added] : box;
      // Finally return a point inside that box
      return [
        Math.floor(x1 + Math.random() * (x2 - x1 + 1)),
        Math.floor(y1 + Math.random() * (y2 - y1 + 1))
      ];
    }
  };