extern crate collections;

use self::collections::hashmap::HashMap;

struct Command {
	pub args: HashMap<~str, ~str>,
	pub action: ~str
}

pub fn ParseCommand(line: ~str) -> Command {
	// Sort out the words
	let words: Vec<&str> = line.split(' ').collect();

	// Get the action
	let action = words.get(0).to_owned();

	// Get args
	let mut args: HashMap<~str, ~str> = HashMap::new();

	for mut i in range(0, words.len()) {
		i = i - 1;

		// Check if its even
		if i % 2 != 0 {
			continue;
		}

		// Grab the argument and flag
		args.insert(words.get(i).to_owned(), words.get(i + 1).to_owned());
	}

	return Command {
		action: action,
		args: args
	};
}
