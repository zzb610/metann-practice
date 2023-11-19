#include <cstddef>
#include <iostream>
#include <vector>

template <typename T>
struct GetSize_ {
    static constexpr std::size_t value = sizeof(T);
};

template <typename T>
static constexpr std::size_t GetSize =  GetSize_<T>::value;


int main() {
    std::cout << "GetSize_<int>::value: " << GetSize_<int>::value << "\n";
    std::cout << "GetSize<int>: " << GetSize<int> << "\n";
    std::cout << "GetSize<int>: " << GetSize_<float>::value << "\n";
    std::cout << "GetSize<float>: " << GetSize<float> << "\n";
    std::cout << "GetSize_<std::vector<int>>::value: "<< GetSize_<std::vector<int>>::value << "\n";
    std::cout << "GetSize<std::vector<int>>: " << GetSize<std::vector<int>> << "\n";

    return 0;
}