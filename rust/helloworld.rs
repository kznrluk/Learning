// 2018-02-27~ Rust

fn main() {
    let words = "Rust";
    hello_world(words);
}

fn hello_world(language: &str) {
    println!("My first {} program", language);
}