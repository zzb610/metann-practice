#include <cstddef>
#include <iostream>
#include <vector>

template <typename T>
struct Obj {

    template<typename N>
    using func = Obj<N>;
};
 
int main() {
   Obj<int>::template func<float>:: template func<int>::func<float>;
   return 0;
}