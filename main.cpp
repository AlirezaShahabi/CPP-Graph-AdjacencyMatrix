

#include "Graph.h"
#include <string>
#include <iostream>

int main() {
    
    Graph<std::string> g1;
    
    g1.add_vertex("alex");
    g1.add_vertex("george");
    g1.add_vertex("sara");
    g1.add_vertex("sam");
    g1.add_vertex("tim");
    g1.add_vertex("mike");
    
    g1.add_edge("alex","george",1);
    g1.add_edge("alex","sara",1);
    g1.add_edge("george","sam",1);
    g1.add_edge("sara","sam",1);
    g1.add_edge("sara","tim",1);
    g1.add_edge("sam","tim",1);
    g1.add_edge("george","mike",1);
    g1.add_edge("sam","mike",1);
    
    std::vector<std::string> neighbors;
    g1.find_adj_vertices("alex", neighbors);
    for (auto a:neighbors) {std::cout << a << " ";}
    std::cout << std::endl;
    
    neighbors.clear();
    g1.find_adj_vertices("sara", neighbors);
    for (auto a:neighbors) {std::cout << a << " ";}
    std::cout << std::endl;
    
    neighbors.clear();
    g1.find_adj_vertices("sam", neighbors);
    for (auto a:neighbors) {std::cout << a << " ";}
    std::cout << std::endl;
    
    std::cout << g1.check_connection("sara","mike") << std::endl;
    std::cout << g1.check_connection("sam","george") << std::endl;

    return 0;
}


