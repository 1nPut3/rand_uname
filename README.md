# Rand Uname

A random username generator for privacy focused or lazy individuals.

This program takes in order a verb, noun, and a random two diget number to make a random username.

Example: GrippingRhino49

## Installation

Run install.sh. This will compile the binary, copy the default noun and verb file to /etc/rand_uname, and copy rand_uname to /usr/bin/rand-uname

```bash
./install.sh
```

## Usage

```bash
# Defaults to default noun and verb list.
rand-uname

# Specify a custom noun file
rand-uname custom_noun.txt

# Specify a custome noun and verb file
rand-uname custom_noun.txt custom_verb.txt
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

## License

[GPL-3.0](https://choosealicense.com/licenses/gpl-3.0/)