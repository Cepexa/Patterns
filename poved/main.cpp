#include "strategy.h"
#include "builder.h"
#include "commander.h"

int main(){

    system("chcp 1251 > nul");

    strategy();
    std::cout << std::endl;
    command();
    std::cout << std::endl;
    builder();
    std::cout << std::endl;

    system("pause");
}
