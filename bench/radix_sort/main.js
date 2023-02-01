// data Arr
var NULL = 0;
var LEAF = 1;
var NODE = 2;
var Null = {$: NULL};
var Leaf = (value) => ({$: LEAF, value});
function Node(left, right) {
  return {$: NODE, left, right};
};

// data Map
var FREE = 0;
var USED = 1;
var BOTH = 2;
var Free = {$: FREE};
var Used = {$: USED};
function Both(left, right) {
  return {$: BOTH, left, right}
};

function toMap(t) {
  if (t.$ === NULL) {
    return Free;
  } else if (t.$ === LEAF) {
    return radix(t.value);
  } else {
    return merge(toMap(t.left), toMap(t.right));
  }
};

function toArr(x, m) {
  if (m.$ === FREE) {
    return Null;
  } else if (m.$ === USED) {
    return Leaf(x);
  } else {
    return Node(toArr(x * 2 + 0, m.left), toArr(x * 2 + 1, m.right));
  }
};

// sort :: Arr -> Arr
function sort(t) {
  return toArr(0, toMap(t));
};

// toMap :: Arr -> Map
function toMap(t) {
  if (t.$ === NULL) {
    return Free;
  } else if (t.$ === LEAF) {
    return radix(t.value);
  } else {
    return merge(toMap(t.left), toMap(t.right));
  }
};

// toArr :: Word64 -> Map -> Arr
function toArr(x, m) {
  if (m.$ === FREE) {
    return Null;
  } else if (m.$ === USED) {
    return Leaf(x);
  } else {
    return Node(toArr(x * 2 + 0, m.left), toArr(x * 2 + 1, m.right));
  }
};

// merge :: Map -> Map -> Map
function merge(a, b) {
  if (a.$ === FREE) {
    return b;
  } else if (b.$ === FREE) {
    return a;
  } else if (a.$ === USED) {
    return b;
  } else if (b.$ === USED) {
    return a;
  } else {
    return Both(merge(a.left, b.left), merge(a.right, b.right));
  }
};

// radix :: Word64 -> Map
function radix(n) {
  var r0 = Used;
  var r1 = u60_swap(n & 1, r0, Free);
  var r2 = u60_swap(n & 2, r1, Free);
  var r3 = u60_swap(n & 4, r2, Free);
  var r4 = u60_swap(n & 8, r3, Free);
  var r5 = u60_swap(n & 16, r4, Free);
  var r6 = u60_swap(n & 32, r5, Free);
  var r7 = u60_swap(n & 64, r6, Free);
  var r8 = u60_swap(n & 128, r7, Free);
  var r9 = u60_swap(n & 256, r8, Free);
  var rA = u60_swap(n & 512, r9, Free);
  var rB = u60_swap(n & 1024, rA, Free);
  var rC = u60_swap(n & 2048, rB, Free);
  var rD = u60_swap(n & 4096, rC, Free);
  var rE = u60_swap(n & 8192, rD, Free);
  var rF = u60_swap(n & 16384, rE, Free);
  var rG = u60_swap(n & 32768, rF, Free);
  var rH = u60_swap(n & 65536, rG, Free);
  var rI = u60_swap(n & 131072, rH, Free);
  var rJ = u60_swap(n & 262144, rI, Free);
  var rK = u60_swap(n & 524288, rJ, Free);
  var rL = u60_swap(n & 1048576, rK, Free);
  var rM = u60_swap(n & 2097152, rL, Free);
  var rN = u60_swap(n & 4194304, rM, Free);
  var rO = u60_swap(n & 8388608, rN, Free);
  return rO;
};

// u60_swap :: Word64 -> Map -> Map -> Map
function u60_swap(n, a, b) {
  if (n === 0) {
    return Both(a, b);
  } else {
    return Both(b, a);
  }
};

// reverse' :: Arr -> Arr
function reverse(t) {
  if (t.$ === NULL) {
    return Null;
  } else if (t.$ === LEAF) {
    return Leaf(t.value);
  } else {
    return Node(reverse(t.right), reverse(t.left));
  }
};

// sum' :: Arr -> Word64
function sum(t) {
  if (t.$ === NULL) {
    return 0;
  } else if (t.$ === LEAF) {
    return t.value;
  } else {
    return sum(t.left) + sum(t.right);
  }
};

function gen_go(n, x) {
  if (n === 0) {
    return Leaf(x);
  } else {
    var x_ = x * 2;
    var y_ = x_ + 1;
    var n_ = n - 1;
    return Node(gen_go(n_, x_), gen_go(n_, y_));
  }
};

function gen(n) {
  return gen_go(n, 0);
};

console.log(sum(sort(reverse(gen(23)))));
