project(ktp-test)
cmake_minimum_required(VERSION 2.6)
find_package(KDE4 REQUIRED)

include(KDE4Defaults)
add_definitions(${KDE4_DEFINITIONS}}
		-DQT_NO_CAST_FROM_ASCII
                 -DQT_NO_KEYWORDS)

add_subdirectory(image-sharer)
add_subdirectory(ktp-test-exec)
