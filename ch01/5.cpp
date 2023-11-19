#include <type_traits>

#include <iostream>

template <typename T>
struct HasType_ {

    // 不知道 type 的类型，设置为指针，就可以传入 nullptr 了
    template <typename U>
    static std::true_type test(typename U::type*);

    // 可变函数参数的匹配权值是最低的
    template <typename U>
    static std::false_type test(...);

    static constexpr bool value = decltype(test<T>(nullptr))::value;
};

template <typename T>
static constexpr bool HasType = HasType_<T>::value;

struct T1 {
  using type = int;
};

struct T2 {};

int main(void) {

  // 先匹配实例，后填参数

  std::cout << HasType<T1> << "\n"; // 1
  std::cout << HasType<T2> << "\n"; // 0
  return 0;
}
