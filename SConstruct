#!/usr/bin/env python3

import os
import subprocess
from SCons.Script import Environment, Return


env = Environment(ENV = os.environ.copy())

# Testing
test_program = SConscript(dirs = ["tests"], variant_dir = ".out/tests", exports = "env")

# Building
dirs = ["src"]
variant_dir = ".out/dist"
program = env.SConscript(dirs = dirs, variant_dir = variant_dir, exports = "env")
print(str(program))

env.Command("test", test_program, os.path.abspath(str(test_program[0])))
env.Command("t", test_program, os.path.abspath(str(test_program[0])))
env.Command("run", program, os.path.abspath(str(program[0])))
env.Command("r", program, os.path.abspath(str(program[0])))

Default()
