var RecentCounter = function () {
  this.arr = [];
  this.start = 0;
};

/** 
 * @param {number} t
 * @return {number}
 */
RecentCounter.prototype.ping = function (t) {
  this.arr.push(t);
  while (this.arr[this.start] < t - 3000) {
    this.start++;
  }
  return this.arr.length - this.start;
};

//Fastest
var RecentCounter = function () {
  this.stream = [];
};

/** 
 * @param {number} t
 * @return {number}
 */
RecentCounter.prototype.ping = function (t) {
  this.stream.push(t);
  while (this.stream[0] < t - 3000) this.stream.shift();
  return this.stream.length;
};

/** 
 * Your RecentCounter object will be instantiated and called as such:
 * var obj = new RecentCounter()
 * var param_1 = obj.ping(t)
 */
