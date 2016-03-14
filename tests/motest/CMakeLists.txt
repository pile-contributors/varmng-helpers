set(SOURCES
    modeltest.cc
    dynamictreemodel.cc
)

set(HEADERS
    modeltest.h
    dynamictreemodel.h
)

add_library(motest STATIC
    ${SOURCES}
    ${HEADERS})

qt5_use_modules(motest Core Test)
