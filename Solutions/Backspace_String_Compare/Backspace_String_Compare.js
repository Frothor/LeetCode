/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */
var backspaceCompare = function (S, T) {
  let S_Stack = [];
  let T_Stack = [];
  for (let i = 0; i < S.length; i++) {
    if (S[i] !== "#") {
      S_Stack.push(S[i]);
    } else {
      S_Stack.pop();
    }
  }
  for (i = 0; i < T.length; i++) {
    if (T[i] !== "#") {
      T_Stack.push(T[i]);
    } else {
      T_Stack.pop();
    }
  }
  if (S_Stack.join("") === T_Stack.join("")) {
    return true;
  } else {
    return false;
  }
};

/////////////////////////////////////////////
var backspaceCompare = function (S, T) {
  return backSpace(S) == backSpace(T);
};

function backSpace(s) {
  const queue = s.split("");
  const stack = [];
  while (queue.length) {
    const c = queue.shift();
    if (c == "#") {
      stack.pop();
    } else {
      stack.push(c);
    }
  }
  return stack.join("");
}
