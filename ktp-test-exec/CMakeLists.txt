
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(ktp-test_SRCS ktp-test.cpp main.cpp)



kde4_add_executable(ktp-test-exec ${ktp-test_SRCS})

target_link_libraries(ktp-test-exec ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ktp-image-sharer)

install(TARGETS ktp-test-exec RUNTIME DESTINATION bin)