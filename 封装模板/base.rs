#![allow(unused, non_snake_case, dead_code)]

use std::fs::write;
use std::io::{self, Read, Write};
struct Scanner {
    input: Vec<u8>,
    idx: usize,
}
impl Scanner {
    fn new() -> Self {
        let mut buf = String::new();
        io::stdin().read_to_string(&mut buf).unwrap();
        Self {
            input: buf.into_bytes(),
            idx: 0,
        }
    }

    fn next<T: std::str::FromStr>(&mut self) -> T {
        while self.idx < self.input.len() && self.input[self.idx].is_ascii_whitespace() {
            self.idx += 1;
        }
        let start = self.idx;
        while self.idx < self.input.len() && !self.input[self.idx].is_ascii_whitespace() {
            self.idx += 1;
        }
        std::str::from_utf8(&self.input[start..self.idx])
            .unwrap()
            .parse()
            .ok()
            .unwrap()
    }

    fn gets<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.next()).collect()
    }
}
fn solve(sc: &mut Scanner, out: &mut impl Write) {}

fn main() {
    let mut sc = Scanner::new();
    let t: usize = sc.next();

    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    for _ in 0..t {
        solve(&mut sc, &mut out);
    }
}
/*
       _____   _                           __   __  _
      / ____| | |                          \ \ / / (_)
     | (___   | |_    ___    _ __     ___   \ V /   _    ___
      \___ \  | __|  / _ \  | '_ \   / _ \   > <   | |  / _ \
      ____) | | |_  | (_) | | | | | |  __/  / . \  | | |  __/
     |_____/   \__|  \___/  |_| |_|  \___| /_/ \_\ |_|  \___|

*/
