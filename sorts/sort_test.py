#!/usr/bin/env python3
from collections import defaultdict
import glob
import random
import subprocess

RANDOM_LIST = []
REPEATS = 10000
SORT_PROGRAMS = glob.glob('*sort')
time_spent = defaultdict(int)

# Remove overhead of creating all these outside of the timing
for i in range(0, 50):
    RANDOM_LIST.append(' '.join([str(random.randint(-32768, 32767)) for t in range(0, 20000)]))


for program in SORT_PROGRAMS:
    for i in range(0, REPEATS):
        proc = subprocess.Popen(['./' + program, RANDOM_LIST[random.randint(0, 49)]],
                                stdout=subprocess.PIPE)

        time, _ = proc.communicate()
        time_spent[program] += int(time.strip())

    print('Total time running {repeats} iterations for '
          '{program} is {time}'.format(repeats=REPEATS, program=program, time=time_spent[program]))
