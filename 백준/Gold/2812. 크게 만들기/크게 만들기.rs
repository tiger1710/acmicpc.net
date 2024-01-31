// 2812 크게 만들기

use std::io::Read;

fn main() {
    let mut input = String::new();
    std::io::stdin()
        .read_to_string(&mut input)
        .expect("read error");
    let mut input = input.split_whitespace();

    let _ = input.next().expect("n error");
    let mut k = input
        .next()
        .expect("k error")
        .parse()
        .expect("k parse error");
    let num = input.next().expect("num error");

    let mut stack = Vec::new();
    for c in num.chars() {
        while 0 < k && !stack.is_empty() && stack.last().expect("stack last error") < &c {
            stack.pop();
            k -= 1;
        }
        stack.push(c);
    }

    while 0 < k {
        stack.pop();
        k -= 1;
    }

    let ans = stack.iter().collect::<String>();
    println!("{ans}");
}
