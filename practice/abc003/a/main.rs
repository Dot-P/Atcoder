use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let n: f32 = input.trim().parse().expect("Please type a number!");

    let mut ans: f32 = 0.0;
    for i in 1..=(n as i32) {
        ans += 1.0 / n * (i as f32) * 10000.0;
    }

    println!("{}", ans);
}
