#ifndef FLOYD_H
#define FLOYD_H

#define INF INFINITY

#include <vector>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <math.h>

class Network {
public:
    std::string name;
    long long size;
    std::vector<std::vector<float>> dmatrix; // distance matrix
    std::vector<std::vector<std::string>> nmatrix; // node matrix

    Network(std::string name, std::vector<std::vector<float>> d, std::vector<std::vector<std::string>> n) {
        if (d[0].size() == d.size()) {
            if (n[0].size() == n.size()) {
                this->name = name;
                this->size = d[0].size();
                this->dmatrix = d;
                this->nmatrix = n;
            }
            else {
                this->~Network();
            }
        }
        else {
            this->~Network();
        }
    }
    ~Network(){}
    
    void print();

    void floyd();
    void shortest_path();
};

#endif