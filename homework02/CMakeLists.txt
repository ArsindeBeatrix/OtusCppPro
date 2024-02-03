cmake_minimum_required(VERSION 3.16)

project(OtusCppPro)

# файлы проекта
add_executable(
    hw_02
    main.cpp
)

# параметры проекта
set_target_properties(hw_02 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# указываем папку до тестов
add_subdirectory(gtests)