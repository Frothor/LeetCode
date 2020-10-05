var bitwiseComplement = function (N) {
  if (N === 0) return 1;

  // get the reversed binary string
  let bi = "";
  while (N > 0) {
    bi += N % 2 === 1 ? "0" : "1";
    N = Math.floor(N / 2);
  }

  // calculate the complement
  let sum = 0, mul = 1;
  for (let digit of bi) {
    if (digit === "1") sum += mul;
    mul *= 2;
  }
  return sum;
};

//Most common
/**
 * @param {number} N
 * @return {number}
 */
var bitwiseComplement = function (N) {
  if (N === 0) return 1;
  if (N === 1) return 0;

  let base = Math.floor(Math.log2(N));
  let x = (1 << base + 1) - 1;
  return N ^ x;
};

//Second fastest
/**
 * @param {number} N
 * @return {number}
 */
var bitwiseComplement = function (N) {
  const arr = N.toString(2).split("");
  const compliment = [];

  for (const digit of arr) {
    if (digit === "1") {
      compliment.push(0);
    } else if (digit === "0") {
      compliment.push(1);
    }
  }

  return parseInt(compliment.join(""), 2);
};

//Fastest
function toBinary(n) {
  if (n === 0) {
    return [0];
  }
  const binary = [];
  while (n != 0) {
    const currentDigit = n % 2;
    binary.unshift(currentDigit);
    n = (n - currentDigit) / 2;
  }
  return binary;
}

function fromBinary(binary) {
  let n = 0;
  for (let i = 0; i < binary.length; i++) {
    const digit = binary[binary.length - 1 - i];
    n += digit * Math.pow(2, i);
  }
  return n;
}

function flip(binary) {
  return binary.map((value) => 1 - value);
}

/**
 * @param {number} N
 * @return {number}
 */
var bitwiseComplement = function (N) {
  return fromBinary(flip(toBinary(N)));
};
