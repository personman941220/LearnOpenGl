# CMakeList.txt: opengl1_c 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("OPENGI")

# 将源代码添加到此项目的可执行文件。
add_executable (OPENGI "opengl1_c.cpp" "opengl1_c.h" "deps/glad/include/glad/glad.h" "deps/glad/include/KHR/khrplatform.h" "deps/glad/src/glad.c" "deps/glfw_win/include/GLFW/glfw3.h" "deps/glfw_win/include/GLFW/glfw3native.h")

# TODO: 如有需要，请添加测试并安装目标。

#-- 防止 第三方库h文件 报 warnings --
target_include_directories ( OPENGI SYSTEM PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/deps
    )


#-- glfw --
target_include_directories ( OPENGI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/deps/glfw_win/include)

add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/deps/glad)
target_link_libraries( OPENGI
        glad
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/glfw_win/lib-vc2017/glfw3.lib
        )
