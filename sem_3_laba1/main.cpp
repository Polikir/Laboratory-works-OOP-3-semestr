#include <iostream>
using namespace std;

#include <iostream>
#include "menu.h"
#pragma once
using namespace std;
#include "Tests.h"

int main(int argc, char **argv) {
    std::cout << R"(
.----------------.  .----------------.  .----------------.  .----------------.     .----------------.
| .--------------. || .--------------. || .--------------. || .--------------. |   | .--------------. |
| |   _____      | || |      __      | || |   ______     | || |      __      | |   | |     __       | |
| |  |_   _|     | || |     /  \     | || |  |_   _ \    | || |     /  \     | |   | |    /  |      | |
| |    | |       | || |    / /\ \    | || |    | |_) |   | || |    / /\ \    | |   | |    `| |      | |
| |    | |   _   | || |   / ____ \   | || |    |  __'.   | || |   / ____ \   | |   | |     | |      | |
| |   _| |__/ |  | || | _/ /    \ \_ | || |   _| |__) |  | || | _/ /    \ \_ | |   | |    _| |_     | |
| |  |________|  | || ||____|  |____|| || |  |_______/   | || ||____|  |____|| |   | |   |_____|    | |
| |              | || |              | || |              | || |              | |   | |              | |
| '--------------' || '--------------' || '--------------' || '--------------' |   | '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'     '----------------'
)" << '\n';
    Test();
    menu();


}
