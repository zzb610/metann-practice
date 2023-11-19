#include <cstddef>
#include <iostream>
#include <vector>



template <typename T, int num>
struct CheckTypeIsSizeAs_ {
    constexpr static bool value = sizeof(T) == num;
};

template <typename T, int num>
constexpr bool CheckTypeIsSizeAs = CheckTypeIsSizeAs_<T, num>::value;

int main() {
     std::cout << "CheckTypeIsSizeAs<int, 4> " << CheckTypeIsSizeAs<int, 4> << "\n";
     std::cout << "CheckTypeIsSizeAs<int, 5>: " << CheckTypeIsSizeAs<int, 5> << "\n";
     std::cout << "CheckTypeIsSizeAs<std::vector<int>,: " << CheckTypeIsSizeAs<std::vector<int>, 24> << "\n";     
    return 0;
}