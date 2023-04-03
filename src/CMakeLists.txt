add_library(LibGf gf.cpp)
target_include_directories(LibGf PUBLIC ../include)
target_link_libraries(LibGf PRIVATE LibCurses::LibCurses)
target_compile_features(LibGf PUBLIC cxx_std_20)

