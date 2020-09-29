var checkValidString = function (s) {
  const openStack = [];
  const starStack = [];

  for (let i = 0; i < s.length; i++) {
    if (s[i] === "(") {
      openStack.push(i);
    } else if (s[i] === "*") {
      starStack.push(i);
    } else {
      if (openStack.length > 0) {
        openStack.pop();
      } else if (starStack.length > 0) {
        starStack.pop();
      } else {
        return false;
      }
    }
  }

  let i = openStack.length - 1;
  let j = starStack.length - 1;

  while (openStack[i] < starStack[j]) {
    openStack.pop();
    starStack.pop();
    i--;
    j--;
  }

  if (openStack.length === 0) {
    return true;
  } else {
    return false;
  }
};

//Fastest
/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function (s) {
  var a = s.split("");
  return checkOneWay(a) && checkOneWay(invert(a));
};

var checkOneWay = function (a) {
  var lvl = 0;
  var stars = 0;
  for (var i = 0; i < a.length; i++) {
    var c = a[i];
    if (c === "(") {
      lvl++;
    }
    if (c === ")") {
      lvl--;
    }
    if (c === "*") {
      stars++;
    }
    if (lvl < 0) {
      stars--;
      lvl++;
    }
    if (stars < 0) {
      return false;
    }
  }
  return true;
};

var invert = function (a) {
  return a.reverse().map((c) => {
    if (c === "(") {
      return ")";
    } else if (c === ")") {
      return "(";
    } else {
      return c;
    }
  });
};
