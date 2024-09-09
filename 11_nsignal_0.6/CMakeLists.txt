#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(B1)

# Set the policy for recognizing numbers and boolean constants
if(POLICY CMP0012)
  cmake_policy(SET CMP0012 NEW)
endif()

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
#set(Geant4_DIR /home/gy/geant4/build)
set(Geant4_DIR /nc1test1/zxr/Geant4/build)

# 获取当前 CMakeLists.txt 文件所在的目录
set(CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# 构建 CADMesh 库的路径
set(CADMesh_LIB_DIR /nc1test1/zxr/Geant4_projects/CADMesh/build)
set(CADMesh_DIR "/usr/local/lib/cmake/cadmesh-2.0.0")


if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()
#----------------------------------------------------------------------------
# 手动设置Assimp库路径和包含目录
#
set(ASSIMP_LIBRARIES /usr/lib/x86_64-linux-gnu/libassimp.so)
include_directories(/usr/include/assimp)

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#
add_executable(exampleB1 exampleB1.cc ${sources} ${headers})
# target_link_libraries(exampleB1 ${Geant4_LIBRARIES})

# 链接 CADMesh 和 Assimp 库
target_link_libraries(exampleB1 ${Geant4_LIBRARIES} ${TETGEN_LIB} ${ASSIMP_LIBRARIES} ${CADMesh_LIB_DIR}/libcadmesh.so)

#----------------------------------------------------------------------------
# Copy all scripts to the build directory, i.e. the directory in which we
# build B1. This is so that we can run the executable directly because it
# relies on these scripts being in the current working directory.
#
set(EXAMPLEB1_SCRIPTS
  exampleB1.in
  exampleB1.out
  init_vis.mac
  ngamma.mac
  vis.mac
  )

foreach(_script ${EXAMPLEB1_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()

#----------------------------------------------------------------------------
# For internal Geant4 use - but has no effect if you build this
# example standalone
#
add_custom_target(B1 DEPENDS exampleB1)

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS exampleB1 DESTINATION bin)

