#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> m;

    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    m[4] = "four";
    m[5] = "five";
    m[6] = "six";
    m[7] = "one";

std::string s = "hello";
std::string p = "world";
    std::cout <<s + p;

}
