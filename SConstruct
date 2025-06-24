#!/usr/bin/env python3

import os
import subprocess
from SCons.Script import Environment, Return


runner_env = Environment(ENV = os.environ.copy())

# Testing
test_program = SConscript(dirs = ["tests"], variant_dir = "build/tests")

# Building
program = SConscript(dirs = ["src"], variant_dir = "build/dist")

runner_env.Command("test", test_program, os.path.abspath(str(test_program[0])))
runner_env.Command("t", test_program, os.path.abspath(str(test_program[0])))
runner_env.Command("run", program, os.path.abspath(str(program[0])))
runner_env.Command("r", program, os.path.abspath(str(program[0])))

Default()
