
fn go(switches: &[char], i: usize) -> usize {
    if switches.len() <= i {
        return 0;
    }

    let exp = 2usize.pow((switches.len() - i) as u32) - 1; 
    if switches[i] == '1' {
        exp - go(switches, i + 1)
    } else {
        go(switches, i + 1)
    }
}
fn main() {
    let mut input = String::new();
    std::io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let t = input.trim().parse().expect("Failed to parse input");

    for _ in 0..t {
        let mut input = String::new();
        std::io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        let switches = input.trim().chars().collect::<Vec<char>>();
        let result = go(&switches, 0);
        println!("{result}");
    }
}
