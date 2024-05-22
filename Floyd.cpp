
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
        // std::cout << std::endl;
        // std::cout << "ITERATION " << iteration << std::endl;
        // std::cout << std::endl;
        // this->print();
    }
    return;
}

std::string Network::shortest_path(std::string start, std::string end) {
    std::string path = "";
    int distance = 0;
    this->floyd();
    path += "   " + std::to_string(distance);
    return path;
}