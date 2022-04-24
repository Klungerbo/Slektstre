add_executable(main
        main.cpp
        ../colsole/console.hpp)
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/include)
