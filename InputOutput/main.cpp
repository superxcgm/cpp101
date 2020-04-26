//
// Created by Yujia Li on 2020/4/25.
//
#include <iostream>
#include <fstream>
#include <string>

const int BUF_SIZE = 1024;

bool copy_file(const std::string &src, const std::string &dest) {
    std::ifstream f_in(src, std::ios::in | std::ios::binary);
    std::ofstream f_out(dest, std::ios::out | std::ios::binary | std::ios::trunc);

    if (!f_in || !f_out) {
        return false;
    }

    char buf[BUF_SIZE];
    while (!f_in.eof()) {
        f_in.read(buf, BUF_SIZE);
        f_out.write(buf, f_in.gcount());
    }

    // 如果没有释放，可能导致资源泄漏
    f_in.close();
    f_out.close();
    return true;
}

namespace InputOutput {
    int main() {
//        int a;
//        int index = 0;
//        std::fstream f_out("testBuffer.txt", std::ios::app);
////        if (!fout) {
//        if (f_out.fail()) {
//            std::cout << "Open file failed." << std::endl;
//            return 1;
//        }
//
//        while (std::cin >> a) {
//            f_out << "The numbers are: " << a << std::endl;
////            std::cout << "The numbers are: " << a << std::endl;
//            index++;
//            if (index == 5) {
//                break;
//            }
//        }
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 丢弃行缓冲的剩下的内容
//        char ch;
//        std::cin >> ch;
//        f_out << "The last char is: " << ch << std::endl;
//
//        f_out.close();

        std::cout << copy_file("weight.png", "haha.png");
        return 0;
    }
}
