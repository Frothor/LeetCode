var rangeBitwiseAnd = function (m, n) {
  let count = 0;
  while (m !== n) {
    m >>= 1;
    n >>= 1;
    count++;
  }
  return m <<= count;
};

//Fastest
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var rangeBitwiseAnd = function (m, n) {
  //Turn off the right-most one's bits of n
  while (n > m) {
    n &= (n - 1);
  }

  return n;
};
