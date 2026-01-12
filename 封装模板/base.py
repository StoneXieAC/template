import sys


def input():
    return sys.stdin.readline()


def gets(t=int):
    return map(t, input().split())


def debug(*args):
    print(*args, file=sys.stderr)


def solve():
    pass

if __name__ == "__main__":
    # _t = 1
    _t = int(input())
    for _ in range(_t):
        solve()

#   _____   _                           __   __  _
#  / ____| | |                          \ \ / / (_)
# | (___   | |_    ___    _ __     ___   \ V /   _    ___
#  \___ \  | __|  / _ \  | '_ \   / _ \   > <   | |  / _ \
#  ____) | | |_  | (_) | | | | | |  __/  / . \  | | |  __/
# |_____/   \__|  \___/  |_| |_|  \___| /_/ \_\ |_|  \___|
