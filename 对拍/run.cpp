// 自动对拍脚本
#include <bits/stdc++.h>

int main() {
    do {
        system("gen.exe > in.txt");
        system("std.exe < in.txt > std.txt");
        system("main.exe < in.txt > out.txt");
    } while (!system("fc std.txt out.txt"));
    return 0;
}