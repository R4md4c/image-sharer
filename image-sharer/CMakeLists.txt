project (image-sharer)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

set(image_sharer_SRCS  imagebinsharer.cpp 
	simplestimagehostingsharer.cpp 
	abstractsharer.cpp
	mpform.cpp
	imgursharer.cpp
        shareprovider.cpp
        )

set( image_sharer_HDRS
    imgursharer.h
    shareprovider.h
)

find_package(QJson REQUIRED)

include_directories( ${KDE4_INCLUDES} ${QJSON_INCLUDE_DIR})

add_definitions( ${KDE4_DEFINITIONS} )

kde4_add_library (image-sharer STATIC ${image_sharer_SRCS})
set_target_properties( image-sharer
  PROPERTIES VERSION ${GENERIC_LIB_VERSION} SOVERSION ${GENERIC_LIB_SOVERSION}
)
target_link_libraries(image-sharer
                      ${KDE4_KDECORE_LIBS}
                      ${KDE4_KIO_LIBS}
                      ${QJSON_LIBRARY}
)

#set_target_properties( ktp-image-sharer  PROPERTIES VERSION 5.0.0 SOVERSION 5 )

install( FILES ${image_sharer_HDRS}
  DESTINATION ${INCLUDE_INSTALL_DIR}/ImageSharer
  COMPONENT Devel
)

install(TARGETS image-sharer DESTINATION ${LIB_INSTALL_DIR})





add_subdirectory(cmake)