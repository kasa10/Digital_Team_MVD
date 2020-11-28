cmake_minimum_required(VERSION 3.5)

project(SmartReferenceGUI LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

qt5_add_resources(SOURCES resources.qrc)

find_package(Threads REQUIRED)
find_package(ZLIB REQUIRED)

set(EJDB_DIR "/apps/ejdb/release")
include_directories(${EJDB_DIR}/include)


  add_executable(SmartReferenceGUI
    main.cpp
    mainwindow.cpp mainwindow.h mainwindow.ui
    machinelearnitem.h machinelearnitem.cpp machinelearnitem.ui
    nlohmann/json.hpp
    highlighter.h highlighter.cpp
    forms/totallyeditordialog.h forms/totallyeditordialog.cpp forms/totallyeditordialog.ui
    forms/totallyeditoritem.h forms/totallyeditoritem.cpp forms/totallyeditoritem.ui
    handlerengine.h handlerengine.cpp
    ejdbcontroller.h ejdbcontroller.cpp
    ${SOURCES}
  )

target_link_libraries(SmartReferenceGUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    PRIVATE ${EJDB_DIR}/lib/libejdb-1.a
    Threads::Threads
    ZLIB::ZLIB)
