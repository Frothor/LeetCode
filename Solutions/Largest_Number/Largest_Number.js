var largestNumber = function (nums) {
  const maxLen = nums.reduce(
    (acc, cur) => Math.max(acc, String(cur).length),
    0,
  );
  const basket = nums.map(
    (n) => [String(n).padEnd(maxLen, Math.max(...[...String(n)])), n]
  );
  basket.sort((a, b) => b[0] - a[0]);
  const res = basket.reduce((acc, cur) => acc + cur[1], "");
  return res == 0 ? "0" : res;
};

//Most common
/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function (nums) {
  if (nums.length <= 1) return nums.toString();

  const numsArr = nums.map((num) => num.toString());

  const compareFn = (a, b) => `${b}${a}` - `${a}${b}`;

  numsArr.sort(compareFn);
  if (numsArr[0] === "0") return "0";
  return numsArr.join("");
};

//Fastest
/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function (nums) {
  if (!nums || !nums.length) return "";
  if (nums.every((num) => num === 0)) return "0";

  nums.sort((a, b) => {
    const firstNumberString = a.toString();
    const secondNumberString = b.toString();

    if (
      firstNumberString + secondNumberString >
        secondNumberString + firstNumberString
    ) {
      return -1;
    } else if (
      firstNumberString + secondNumberString <
        secondNumberString + firstNumberString
    ) {
      return 1;
    }

    return 0;
  });

  // return nums.reduce((answer, currentNumber) => answer + currentNumber, '');
  let answer = "";
  for (let i = 0; i < nums.length; i++) {
    answer = answer + nums[i];
  }
  return answer;
};
