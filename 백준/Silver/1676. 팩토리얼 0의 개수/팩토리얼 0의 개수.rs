// 1676 팩토리얼 0의 개수

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("read error");
    let n = input.trim().parse::<usize>().expect("parse error");

    let cnt5 = n / 5;
    let cnt25 = n / 25;
    let cnt125 = n / 125;

    println!("{}", cnt5 + cnt25 + cnt125);
}