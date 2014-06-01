use std::io;

mod cli;

fn main() {
	::cli::printText("Booting smalldb...", ::cli::System);

	// Load

	::cli::printText("Now running smalldb. ^C to quit.", ::cli::System);

	// Start listening on stdin

	::cli::printText("  Enter command > ", ::cli::Default);
	for line in io::stdin().lines() {
		// Parse the command
	}

	// Shut down

	::cli::printText("Shutting down...", ::cli::System);
}
