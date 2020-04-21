# Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

import os
import subprocess
import multiprocessing

cores = multiprocessing.cpu_count();

if not os.path.exists("build"):
    os.makedirs("build")

if os.name == 'nt':
    os.system('cmd /c "cd build && cmake .. -G \"MinGW Makefiles\" && mingw32-make -j{}"'.format(cores))
    os.system("build\HelloWorld.exe")

if os.name == 'posix':
    os.system('cd build && cmake .. && make -j{}'.format(cores))
    os.system('./build/test/Test')
    os.system('./build/SimpleEngine')
