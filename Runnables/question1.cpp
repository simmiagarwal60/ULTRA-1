#include <iostream>
#include <chrono>
#include "ULTRA/Dijkstra/Dijkstra.h" 
#include "USA-road-d.FLA.gr" 

int main() {
    FloridaGraph graph("USA-road-d.FLA.gr");
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    
    for (int i = 0; i < 200; ++i) {
        int source = getRandomSource(); 
        int target = getRandomTarget(); 

        DijkstraResult result = ULTRA::Dijkstra::runDijkstra(graph, source, target); // Assuming ULTRA::Dijkstra::runDijkstra(graph, source, target) is the correct function call

        // Print the shortest path and its length for each pair
        std::cout << "Shortest Path from " << source << " to " << target << ": " << result.path << std::endl;
        std::cout << "Shortest Path Length: " << result.length << std::endl;
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Total runtime in seconds for 200 random Dijkstra: " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << std::endl;

    return 0;
}