#include <iostream>
#include <string>

int main(){
    const char *p = "Hello";
    for (int i = 0; i <sizeof(p)/sizeof(p[0]); ++i){
        std::cout << i << std::endl;
        std::cout << p[i] << std::endl;
    }
    return 0;
}