pileTarget( "VarMngGui1" GUI)

set( VARMNGGUI1_SOURCES
    main.cc
    mainwindow.cc)

set( VARMNGGUI1_UIS
    mainwindow.ui)

set( VARMNGGUI1_RES
)

set( VARMNGGUI1_LIBS
    varmng
    motest
)

set( VARMNGGUI1_QT_MODS
    Core
    Gui
    Widgets
    Xml
    Sql
)
pileEndTarget( "VarMngGui1" "exe" COPY)
