
add_executable(main
        main.cpp
        ../tests/tests.cpp
        ../tests/catch.hpp)
target_link_libraries(main PUBLIC slektstrelib)
# target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/include)
