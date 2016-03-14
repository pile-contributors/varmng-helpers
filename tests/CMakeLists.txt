# ============================================================================
#
# This file hosts all tests.
#
# If INCLUDE_PILE_SOURCES_DIRECTLY is ON then VARMNG_SOURCES and
# VARMNG_HEADERS are defined we add them to the executable. VARMNG_LIBRARY
# is empty.
#
# On the other hand if INCLUDE_PILE_SOURCES_DIRECTLY is
# OFF then VARMNG_SOURCES and VARMNG_HEADERS are empty and we link
# against VARMNG_LIBRARY that is now the name of the target that
# builds the library.
#
# ============================================================================

find_package(Qt5 QUIET COMPONENTS Core Widgets)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Instruct CMake to run moc automatically when needed.
set (CMAKE_AUTOMOC ON)
set( CMAKE_INCLUDE_CURRENT_DIR ON)

if (NOT INCLUDE_PILE_SOURCES_DIRECTLY)
    set (VARMNG_LIBRARY varmng)
endif()

#add_executable(test_basic
#    ${VARMNG_SOURCES}
#    ${VARMNG_HEADERS}
#    basic.cc)

if (UNIX)
    find_package(Threads REQUIRED)
    list(APPEND GTEST_BOTH_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
    add_definitions(-fPIC)
endif()


#######################################################
#######################################################
#######################################################
#target_link_libraries(test_basic
#    ${GTEST_BOTH_LIBRARIES}
#    ${VARMNG_LIBRARY})
#
#add_test(
#    NAME test_basic
#    COMMAND $<TARGET_FILE:test_basic>)
#######################################################
#######################################################
#######################################################


enable_testing()

add_subdirectory("motest")
add_subdirectory("unit")
add_subdirectory("integration")
