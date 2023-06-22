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

    //find all key value pairs with value equal "one"
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second == "one") {
            std::cout << it->first << " " << it->second << std::endl;
        }
    }
    //another way
    for (auto it = m.begin(); it != m.end(); ++it) {
        if ((*it).second == "one") {
            std::cout << (*it).first << " " << (*it).second << std::endl;
        }
    }
}
