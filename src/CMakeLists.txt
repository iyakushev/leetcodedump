file(GLOB problems *.cpp)

foreach(problem IN ITEMS ${problems})
    cmake_path(GET problem FILENAME fname)
    string(REPLACE ".cpp" "" tname ${fname})
    add_executable(${tname} ${problem})
    target_link_libraries(${tname} PUBLIC fmt::fmt GTest::gtest_main)
    gtest_discover_tests(${tname})
endforeach()
