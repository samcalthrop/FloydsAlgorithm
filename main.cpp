
#include "include/Floyd.h"

int main() {
    std::vector<std::vector<float>> d = {
        {0, 4,   7,   INF }, 
        {4,   0, INF, 9   }, 
        {7,   INF, 0, INF }, 
        {1,   9,   INF, 0 }
    };
    std::vector<std::vector<std::string>> n = {
        {"A", "B", "C", "D"}, 
        {"A", "B", "C", "D"}, 
        {"A", "B", "C", "D"}, 
        {"A", "B", "C", "D"}
    };

    Network net("net", d, n);

    net.print();
    net.floyd();
    net.print();
}