CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(CowboyCoding CXX)

#ADD_DEFINITIONS(-Wall -O4 -D_NDEBUG)
ADD_DEFINITIONS(-Wall -g -O0)

file(GLOB SourceFiles ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB HeaderFiles ${CMAKE_SOURCE_DIR}/src/*.h)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/utils )
SET(CMAKE_EXE_LINKER_FLAGS "-pg")

# find_package ( SFML REQUIRED )

#if( NOT SFML_FOUND )
#     message( FATAL_ERROR "ERROR: SFML not found" )
#else()
#     message( STATUS "SFML found" )
#endif( NOT SFML_FOUND )

ADD_EXECUTABLE(CowboyCoding ${SourceFiles} ${HeaderFiles})

set_target_properties(CowboyCoding PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
        TARGET_LINK_LIBRARIES(CowboyCoding)
        ADD_DEFINITIONS(-D_W32)
elseif (UNIX)
        TARGET_LINK_LIBRARIES(CowboyCoding)
		ADD_DEFINITIONS(-D_UNIX)
endif()
