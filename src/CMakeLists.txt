set(MATH_HEADERS
    "math/divisors.hpp"
    "math/primes.hpp"
    "math/sequences.hpp"
    "math/math.hpp"
)
set(MATH_SOURCES
    "math/divisors.cpp"
    "math/primes.cpp"
    "math/sequences.cpp"
    "math/math.cpp"
)

set(PROBLEMS_HEADERS
    "problems/problem_registry.hpp"
)

set(PROBLEMS_SOURCES
    "problems/1-100/1-20/p1.cpp"
    "problems/1-100/1-20/p2.cpp"
    "problems/1-100/1-20/p3.cpp"
    "problems/1-100/1-20/p4.cpp"
    "problems/1-100/1-20/p5.cpp"
    "problems/1-100/1-20/p6.cpp"
    "problems/1-100/1-20/p7.cpp"
    "problems/1-100/1-20/p8.cpp"
    "problems/1-100/1-20/p9.cpp"
    "problems/1-100/1-20/p10.cpp"
    "problems/1-100/1-20/p11.cpp"
    "problems/1-100/1-20/p12.cpp"
    "problems/1-100/1-20/p13.cpp"
    "problems/1-100/1-20/p14.cpp"
    "problems/1-100/1-20/p15.cpp"
    "problems/1-100/1-20/p16.cpp"
    "problems/1-100/1-20/p17.cpp"
    "problems/1-100/1-20/p18.cpp"
    "problems/1-100/1-20/p19.cpp"
    "problems/1-100/1-20/p20.cpp"
    "problems/1-100/21-40/p21.cpp"
    "problems/1-100/21-40/p22.cpp"
    "problems/1-100/21-40/p23.cpp"
    "problems/1-100/21-40/p24.cpp"
)

add_executable(ProjectEulerApp
    "problem_runner.cpp"
    ${MATH_HEADERS}
    ${MATH_SOURCES}
    ${PROBLEMS_HEADERS}
    ${PROBLEMS_SOURCES}
)

target_include_directories(ProjectEulerApp
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

add_custom_command(TARGET ProjectEulerApp POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${PROJECT_SOURCE_DIR}/data $<TARGET_FILE_DIR:ProjectEulerApp>/data
)
