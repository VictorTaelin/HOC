bigdata = function(size) {
  if (size <= 1) {
    return 1;
  } else {
    return {
      left  : bigdata(size / 2),
      right : bigdata(size / 2),
    };
  }
}

sum = function(tree) {
  if (typeof tree == "number") {
    return tree;
  } else {
    return sum(tree.left) + sum(tree.right);
  }
}

console.log(sum(bigdata(2 ** 26)));
