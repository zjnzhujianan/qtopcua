# Generated from qtopcua.pro.

cmake_minimum_required(VERSION 3.15.0)

include(.cmake.conf)
project(QtOpcUa
    VERSION "${QT_REPO_MODULE_VERSION}"
    DESCRIPTION "Qt OpcUa Libraries"
    HOMEPAGE_URL "https://qt.io/"
    LANGUAGES CXX C
)

# special case begin
find_package(Qt6 ${PROJECT_VERSION} CONFIG REQUIRED COMPONENTS BuildInternals Core Network)
find_package(Qt6 ${PROJECT_VERSION} CONFIG OPTIONAL_COMPONENTS Gui Quick QuickTest Widgets)
# special case end

# special case begin
# Needed for qt_opcua_disable_optimizations_in_current_dir.
include(src/opcua/Qt6OpcUaMacros.cmake)
# special case end

if(QNX)
    message(NOTICE "Skipping the build as the condition \"NOT QNX\" is not met.")
    return()
endif()
if(WASM)
    message(NOTICE "Skipping the build as the condition \"NOT WASM\" is not met.")
    return()
endif()
qt_build_repo()
