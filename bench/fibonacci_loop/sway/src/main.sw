script;

fn fun(n: u64) -> u64 {
  let mut i:u64 = n;
  let mut a:u64 = 0;
  let mut b:u64 = 1;
  while i > 0 {
    let x = b;
    i = i - 1;
    a = b;
    b = a + 1; // should be `a + b`, but causes u64 overflow, which crashes FuelVM
  }
  return a;
}

fn main() {
  assert(true);
}

#[test]
fn test_meaning_of_life() {
  let x = fun(60000);
  assert(true);
}
