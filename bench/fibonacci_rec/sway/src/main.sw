script;

fn fun(n: u64) -> u64 {
  let mut stack : Vec<u64> = Vec::new();
  stack.push(n);
  let mut result = 0;
  while true {
    match stack.pop() {
      Option::Some(x) => {
        if x <= 1 {
          result += x;
        } else {
          stack.push(x - 1);
          stack.push(x - 2);
        }
      }
      Option::None => {
        return result;
      }
    }
  }
  return result;
}

fn main() {
  assert(true);
}

#[test]
fn test_meaning_of_life() {
  let x = fun(19);
  assert(true);
}

