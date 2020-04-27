project ( LAS )

cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# definitions for VC++
add_definitions( -DCOMPILE_AS_DLL  -D_CRT_SECURE_NO_WARNINGS )

add_definitions( -DUNORDERED )

include_directories( BEFORE LASzip/src LASlib/inc  )

file( GLOB LASLIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/LASlib/src/*.cpp")
file( GLOB LASZIP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/LASzip/src/*.cpp")

add_library( las SHARED ${LASLIB_SOURCES} ${LASZIP_SOURCES} )

install(TARGETS las
         DESTINATION lib)
install(DIRECTORY LASlib/inc/ DESTINATION include/LASlib
        FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY LASzip/src/ DESTINATION include/LASzip
        FILES_MATCHING PATTERN "*.hpp")

