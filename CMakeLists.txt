project(ktp-test)
cmake_minimum_required(VERSION 2.6)
find_package(KDE4 REQUIRED)

include(KDE4Defaults)

add_subdirectory(image-sharer)
add_subdirectory(ktp-test-exec)
