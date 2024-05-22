
#include "include/Floyd.h"

void Network::print() {
    std::cout << std::endl;
    std::cout << "  + Distance";
    for (int i=0; i<(this->size)*4 - 8; ++i) {
        std::cout << " ";
    }
    std::cout << "  + Arc";
    std::cout << std::endl;
    std::cout << "  | ";
    for (int i=0; i<this->size; ++i) {
        std::cout << this->nmatrix[i][i] << "   ";
    }
    std::cout << "  | ";
    for (int i=0; i<this->size; ++i) {
        std::cout << this->nmatrix[i][i] << "   ";
    }
    std::cout << std::endl;
    std::cout << "--+-";
    for (int i=0; i<this->size-1; ++i) {
        std::cout << "--+-";
    }
    std::cout << "------+-";
    for (int i=0; i<this->size-1; ++i) {
        std::cout << "--+-";
    }
    std::cout << "--->";
    std::cout << std::endl;
    for (int i=0; i<this->size; ++i) {
        std::cout << this->nmatrix[i][i] << " | ";
        for (int j=0; j<this->size; ++j) {
            if (this->dmatrix[i][j] == 0) {
                std::cout << "-";
            } 
            else {
                std::cout << this->dmatrix[i][j];
            }
            if (this->dmatrix[i][j] < 10) {
                std::cout << "   ";
            }
            else if (this->dmatrix[i][j] < 100) {
                std::cout << "  ";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "  | ";
        for (int j=0; j<this->size; ++j) {
            std::cout << this->nmatrix[i][j] << "   ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Network::floyd() {
    for (int iteration=0; iteration<this->size; ++iteration) {
        for (int i=0; i<this->size; ++i) {
            for (int j=0; j<this->size; ++j) {
                if (i == iteration || j == iteration || (i == iteration && j == iteration) || i == j) {
                    continue;
                }
                else {
                    if (this->dmatrix[i][j] > (this->dmatrix[iteration][j] + this->dmatrix[i][iteration])) {
                        this->dmatrix[i][j] = (this->dmatrix[iteration][j] + this->dmatrix[i][iteration]);
                        this->nmatrix[i][j] = this->nmatrix[iteration][iteration];
                    }
                }
            }
        }
        // print each iteration:
        // std::cout << std::endl;
        // std::cout << "ITERATION " << iteration << std::endl;
        // std::cout << std::endl;
        // this->print();
    }
    return;
}

std::string Network::shortest_path(std::string start, std::string end) {
    if (start == end) return "";
    int index_current;
    int index_end = get_index(this->nodes, end);
    std::string path = "";
    std::string current = start;
    int distance = 0;
    
    this->floyd();

    while (current != end) {

        // plan:
        // check if node connecting current to end (let's call it `target`) is end.
        // check how to get from current target, and do same process (recursively?).
        // repeat for either side of the `split`. this is probably recursive :(.
        // if target == end, append end to path and end there.
        // otherwise keep going...

        path += current;
        index_current = get_index(this->nodes, current); // assuming get_index() works
        if (this->nmatrix[index_current][index_end] == end) return path;
        current = this->nmatrix[index_current][index_end];
    }

    path += "   " + std::to_string(distance);
    return path;
}

int get_index(std::vector<std::string> vec, std::string str) 
{ 
    auto it = std::find(vec.begin(), vec.end(), str); 
    if (it != vec.end())  
    { 
        return it - vec.begin();
    } 
    return -1;
}
