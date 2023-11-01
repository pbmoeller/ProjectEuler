set(PROBLEMS_HEADERS
    "problems/problem_registry.hpp"
)

set(PROBLEMS_SOURCES
    "problems/1-100/p1.cpp"
    "problems/1-100/p2.cpp"
    "problems/1-100/p3.cpp"
    "problems/1-100/p4.cpp"
    "problems/1-100/p5.cpp"
)

add_executable(ProjectEulerApp
    "problem_runner.cpp"
    ${PROBLEMS_HEADERS}
    ${PROBLEMS_SOURCES}
)

target_include_directories(ProjectEulerApp
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)
