# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)


#Definiciones de compilacion

add_compile_definitions(RTOS=1)
add_compile_definitions(ESP32) 
add_compile_definitions(IDF_TARGET="esp32")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(DSE_Tarea2_Equipo1)
