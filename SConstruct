#!/usr/bin/env python3


import os
import subprocess
from SCons.Script import Environment, Return


env = Environment(ENV = os.environ.copy())

# Testing
test_program = env.SConscript(dirs = ["tests"], variant_dir = ".out/tests", exports = "env")

# Building
program = env.SConscript(dirs = ["src"], variant_dir = ".out/dist", exports = "env")

env.Command("build", program, program)
env.Command("b", program, program)
env.Command("test", test_program, os.path.abspath(str(test_program[0])))
env.Command("t", test_program, os.path.abspath(str(test_program[0])))
env.Command("run", program, os.path.abspath(str(program[0])))
env.Command("r", program, os.path.abspath(str(program[0])))

Default()
