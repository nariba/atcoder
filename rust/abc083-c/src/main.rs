use std::io;

fn read_line() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s
}

macro_rules! from_line {
    ($($a:ident : $t:ty),+) => {
        $(let $a: $t;)+
        {
            let _line = read_line();
            let mut _it = _line.trim().split_whitespace();
            $($a = _it.next().unwrap().parse().unwrap();)+
                assert!(_it.next().is_none());
        }
    };
}

fn seq_ln(start: i64, end: i64) -> i64 {
    let mut tmp = end;
    let mut count = 0;
    while start <= tmp {
        count += 1;
        tmp /= 2;
    }
    count
}

fn main() {
    from_line!(x: i64, y: i64);
    let mut max = 0;
    println!("{}", seq_ln(x, y));
}
