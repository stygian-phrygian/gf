add_executable(example1 example1.cpp)

target_compile_features(example1 PRIVATE cxx_std_20)
target_compile_options(example1 PRIVATE -Wall -Wextra -Wpedantic)

target_link_libraries(example1 PRIVATE LibGf)

