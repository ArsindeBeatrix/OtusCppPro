cmake_minimum_required(VERSION 3.8)

set(PATCH_VERSION "2" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(HomeWork01 VERSION ${PROJECT_VESRION})

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)
add_library(helloworld lib.cpp)

target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(helloworld_cli PRIVATE
    helloworld
)

set_target_properties(helloworld_cli helloworld PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(helloworld_cli PRIVATE
        /W4
    )
    target_compile_options(helloworld PRIVATE
        /W4
    )
else ()
    target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(helloworld PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_NAME "OtusCppPro")

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_subdirectory(gtests)




# Имя выходного пакета OtusCppPro-0.0.6-Linux.deb 
# ( https://github.com/ArsindeBeatrix/OtusCppPro/actions/runs/7603362028/job/20705006757#step:7:19 ), 
# а взять релиз сейчас пытаемся из ./helloworld-0.0.6-Linux.deb 
# ( https://github.com/ArsindeBeatrix/OtusCppPro/actions/runs/7603362028/job/20705006757#step:9:10 ). 
# Имя выходного пакеа по умолчанию соответствует имени проекта 
# https://cmake.org/cmake/help/latest/module/CPack.html#variables-common-to-all-cpack-generators , 
# потюнить можно переменной CPACK_PACKAGE_NAME