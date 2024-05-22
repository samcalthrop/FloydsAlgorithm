#ifndef FLOYD_H
#define FLOYD_H

#define INF INFINITY

#include <vector>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stack>

class Network {
public:
    std::string name;
    long long size;
    std::vector<std::vector<float>> dmatrix; // distance matrix
    std::vector<std::vector<std::string>> nmatrix; // node matrix
    std::vector<std::string> nodes;

    Network(std::string name, std::vector<std::vector<float>> d, std::vector<std::string> n) {
        if (d[0].size() == d.size()) {
            if (n.size() == d.size()) {
                this->name = name;
                this->size = d[0].size();
                this->dmatrix = d;
                for (int i=0; i<this->size; ++i) {
                    this->nmatrix.push_back(n);
                }
                this->nodes = n;
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
    std::string shortest_path(std::string start, std::string end);
};

int get_index(std::vector<std::string> vec, std::string str);

#endif