#include "Graph.hpp"

using namespace std;

int main() {

    Graph *G = new Graph();
    G->parserGraph("/Users/zirael/Projects/C++/FilatovHW/graph1.txt");
    G->showAllSimplePath(5, 18);

    return 0;

}