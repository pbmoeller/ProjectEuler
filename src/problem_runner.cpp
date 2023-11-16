#include "problems/problem_registry.hpp"

#include <iostream>
#include <climits>
#include <chrono>

int main(int argc, char **argv)
{
#ifdef NDEBUG
    const char * configuration = "Release";
#else
    const char * configuration = "Debug";
#endif 

    std::cout << "--- Project Euler - Problem Runner ---" << std::endl;

    int problem = -1;
    if(argc == 2) {
        problem = std::atoi(argv[1]);
    } else {
        std::cout << "\nInsert problem to be solved: " << std::flush;
        std::cin >> problem;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(std::cin.fail()) {
            std::cout << "\n ERROR: Invalid input." << std::endl;
            return 1;
        }
    }
    std::cout << "The Runner will try to solve problem: " << problem << std::endl;

    try {
        std::chrono::time_point begin = std::chrono::system_clock::now();
        int64_t solution = ProblemRegistry::getInstance().execute(problem);
        std::chrono::time_point end = std::chrono::system_clock::now();

        std::cout << "The solution for problem " << problem << " is \"" << solution << "\" !" << std::endl;
        std::cout << "The solver took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()
            << " ms (" << configuration << " Build)." << std::endl;
    } catch(std::exception &e) {
        std::cerr << "Exception caught while calculating problem: " << problem << std::endl;
    }

    return 0;
}
