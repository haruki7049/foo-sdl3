# foo-sdl3

My hobby practice project to use SDL3.

# Building/Testing/Running

First, execute `nix-shell`. `/flake.nix` and `/shell.nix` is used by the command.

Then, there are some environment variables as `$PKG_CONFIG_PATH` and `$CFLAGS`, and you can use scons. Use as the following:

```sh
# Building
scons

# Testing
scons test
scons t

# Running
scons run
scons r
```
