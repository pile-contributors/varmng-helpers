
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Will accumulate the source files
list(APPEND modules_testing_src
    "manager-tests")

if (modules_testing_src)
    list(REMOVE_DUPLICATES modules_testing_src)
    add_executable("internal-test"
        ${modules_testing_src}
    )
    qt5_use_modules("internal-test" Core Widgets Sql)
    target_link_libraries ( "internal-test"
        ${GTEST_BOTH_LIBRARIES}
        ${VARMNG_LIBRARY}
    )
    set (props "${PROJECT_NAME_U}_INTERNAL_TESTS=1")
    set_target_properties (internal-test
        PROPERTIES COMPILE_DEFINITIONS "${props}"
    )

    add_test(NAME "internal-test"
             WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/build/bin"
             COMMAND "internal-test")

endif (modules_testing_src)

