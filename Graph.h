
// Adjacency matrix:
// store vertices in a list (vector)
// represent edges by a square matrix (n_vertices * n_vertices)

// best representation if graph is too dense 

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

template <typename T> class Graph {
private:
    std::vector<T> vertices;
    std::vector<std::vector<size_t>> edge_mat;
    size_t n_vertices;
    void update_edge_mat(size_t);
public:
    Graph();
    void add_vertex(const T&);
    void add_edge(const T&, const T&, int);
    void find_adj_vertices(const T&, std::vector<T>&);
    bool check_connection(const T&, const T&);
};

#endif

// constructor
template <typename T>
Graph<T>::Graph():vertices(), edge_mat(), n_vertices(0) {}

// add a new vertex to graph
template <typename T> void Graph<T>::add_vertex(const T& obj) {
    ++n_vertices;
    vertices.push_back(obj);
    update_edge_mat(n_vertices - 1);
}

// add a new edge to graph
template <typename T>
void Graph<T>::add_edge(const T& obj1, const T& obj2, int weight) {
    size_t i1 = std::find(vertices.begin(), vertices.end(), obj1)
                - vertices.begin();
    size_t i2 = std::find(vertices.begin(), vertices.end(), obj2)
                - vertices.begin();
    if (i1 < n_vertices && i2 < n_vertices) {
        edge_mat[i1][i2] = weight;
        edge_mat[i2][i1] = weight;
    }
}

// find all adjacent vertices to curr vertex
// Time: O(n_vertices)
// space:O(n_vertices ^ 2)
template <typename T>
void Graph<T>::find_adj_vertices(const T& curr, std::vector<T>& adj_list) {
    size_t curr_index = std::find(vertices.begin(), vertices.end(), curr)
                        - vertices.begin();
    if (curr_index < n_vertices) {
        for (size_t i = 0; i < n_vertices; ++i) {
            if (edge_mat[curr_index][i] != -1) {
                adj_list.push_back(vertices[i]);
            }
        }
    }
}

// check if two vertices are directly connected via an edge
template<typename T>
bool Graph<T>::check_connection(const T& obj1, const T& obj2) {
    size_t i1 = std::find(vertices.begin(), vertices.end(), obj1)
                - vertices.begin();
    size_t i2 = std::find(vertices.begin(), vertices.end(), obj2)
                - vertices.begin();
    if (i1 < n_vertices && i2 < n_vertices && edge_mat[i1][i2] != -1) {
        return true;
    }
    return false;
}


// private utility function to update the size of edge_mat after
// adding a new vertex
template <typename T> void Graph<T>::update_edge_mat(size_t n_old) {
    std::vector<size_t> temp_row(n_vertices, -1);
    std::vector<std::vector<size_t>> temp_mat;
    for (size_t i = 0; i < n_vertices; ++i) {temp_mat.push_back(temp_row);}
    if (!edge_mat.empty()) {
        for (size_t i = 0; i < n_old; ++i) {
            for (size_t j = 0; j < n_old; ++j) {
                if (edge_mat[i][j] != -1) {
                    temp_mat[i][j] = edge_mat[i][j];
                }
            }
        }
    }
    edge_mat = temp_mat;
}





