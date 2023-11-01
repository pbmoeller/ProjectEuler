#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_REGISTRY_HPP
#define PROJECT_EULER_PROBLEMS_PROBLEM_REGISTRY_HPP

// STL
#include <iostream>
#include <functional>
#include <map>

struct Hash
{
    std::size_t operator()(int key) const {
        return static_cast<std::size_t>(key);
    }
};

class ProblemRegistry
{
    using ProblemFunction = std::function<int64_t()>;
    using FunctionMap = std::map<int, ProblemFunction>;
public:
    static ProblemRegistry& getInstance() {
        static ProblemRegistry instance;
        return instance;
    }

    void registerFunction(int problem, ProblemFunction function) {
        m_registry[problem] = function;
    }

    int64_t execute(int problem) {;
        auto it = m_registry.find(problem);
        if(it != m_registry.end()) {
            return it->second();
        } else {
            std::cerr << "Cannot execute solver for problem " << problem
                << "!\nThere is no registered solver." << std::endl;
            return 0;
        }
    }
private:
    ProblemRegistry() = default;
    FunctionMap m_registry;
};

#define REGISTER_FUNCTION(problemId, function)                                      \
namespace {                                                                         \
    struct Problem_##problemId {                                                    \
        Problem_##problemId() {                                                     \
            ProblemRegistry::getInstance().registerFunction(problemId, function);   \
        }                                                                           \
    } reg_problem_##problemId;                                                          \
}

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_REGISTRY_HPP
