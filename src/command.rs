extern crate collections;

use self::collections::hashmap::HashMap;

struct Command {
	action: ~str,
	flags: ~MutableMap<~str, ~str>
}

pub fn ParseCommand(line: ~str) -> Command {
	let words = line.split(' ').collect();
}