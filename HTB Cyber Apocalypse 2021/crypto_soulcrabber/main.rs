use rand::{Rng,SeedableRng};
use rand::rngs::StdRng;
use std::fs;
use std::io::Write;

fn get_rng() -> StdRng {
    let seed = 13371337;
    return StdRng::seed_from_u64(seed);
}

fn rand_xor(input : String) -> String {
    let mut rng = get_rng();
    return input
        .chars()
        .into_iter()
        .map(|c| format!("{:02x}", (c as u8 ^ rng.gen::<u8>())))
        .collect::<Vec<String>>()
        .join("");
}

fn main() -> std::io::Result<()> {
    let flag = fs::read_to_string("flag.txt")?;
    let xored = rand_xor(flag);
    println!("{}", xored);
    let mut file = fs::File::create("out.txt")?;
    file.write(xored.as_bytes())?;
    Ok(())
}
