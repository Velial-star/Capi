cmake_minimum_required(VERSION 3.15)
project(MySFMLGame)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "C:/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit (1)/SFML-2.6.1/lib/cmake/SFML")

find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

add_executable(MySFMLGame main.cpp
        Capybara.h
        Capybara.cpp
        obj.cpp
        obj.h
)

target_link_libraries(MySFMLGame PRIVATE sfml-graphics sfml-window sfml-system)


if(WIN32)
    add_custom_target(copy_assets ALL
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets
            ${CMAKE_BINARY_DIR}/assets
    )
    add_dependencies(MySFMLGame copy_assets)


    add_custom_command(TARGET MySFMLGame POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_RUNTIME_DLLS:MySFMLGame>"
            $<TARGET_FILE_DIR:MySFMLGame>
            COMMAND_EXPAND_LISTS
    )

endif()