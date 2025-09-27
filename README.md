# Anime Control

Anime Control is a command-line tool for controlling Anime Matrix display on
Asus ROG laptops.

It offers the following basic functionalities:

- Turn the Anime Matrix display on or off.
- Set the brightness of the Anime Matrix display.
- Enable or disable the built-in animations.

It can be hooked into power management tools like TLP or systemd or KDE powerdevil
to automatically manage the Anime Matrix display based on power source or battery
level.

# Usage

```shell

# animectl <command> [command options]

```
Where the `<command>` can be one of the following:

- `-e <0|1>`: Enable/Disable the Anime Matrix display.
- `-b <0-3>`: Set the brightness of the Anime Matrix display from a set of 3 brightness
levels.
- `-a <0|1>`: Enable/Disable the built-in animations.

## Examples

```shell

# animectl -e 1        # Turn on the Anime Matrix display

# animectl -b 2        # Set brightness to level 2

# animectl -a 0        # Disable built-in animations

```

# Setup

In order to access the Anime Matrix device without using the root user, you need
to set up an udev rule.

```shell

# nano /etc/udev/rules.d/99-anime-matrix.rules

```

and paste the following line:

```udev

SUBSYSTEM=="hidraw", ATTRS{idVendor}=="0b05", ATTRS{idProduct}=="193b", MODE="0660",
OWNER="1000", GROUP="1000"

```

Then reload the udev rules:

```shell

udevadm control --reload-rules
udevadm trigger

```

# Development

# Inspired to

- [asusctl](https://gitlab.com/asus-linux/asusctl/)
- [g-helper](https://github.com/seerge/g-helper/)
