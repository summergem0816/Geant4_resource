# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# compile CXX with /usr/bin/c++
CXX_FLAGS = -W -Wall -pedantic -Wno-non-virtual-dtor -Wno-long-long -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-variadic-macros -Wshadow -pipe -std=c++11  -g -g   -pthread -fPIC

CXX_DEFINES = -DG4INTY_USE_QT -DG4LIB_BUILD_DLL -DG4UI_USE_QT -DG4UI_USE_TCSH -DG4VIS_USE_OPENGL -DG4VIS_USE_OPENGLQT -DQT_CORE_LIB -DQT_GUI_LIB -DQT_OPENGL_LIB -DQT_PRINTSUPPORT_LIB -DQT_WIDGETS_LIB

CXX_INCLUDES = -I/home/gy/project/TMV/nsingle/include -isystem /home/gy/geant4/src/source/analysis/g4tools/include -isystem /home/gy/geant4/src/source/analysis/accumulables/include -isystem /home/gy/geant4/src/source/analysis/csv/include -isystem /home/gy/geant4/src/source/analysis/factory/include -isystem /home/gy/geant4/src/source/analysis/hntools/include -isystem /home/gy/geant4/src/source/analysis/management/include -isystem /home/gy/geant4/src/source/analysis/root/include -isystem /home/gy/geant4/src/source/analysis/xml/include -isystem /home/gy/geant4/src/source/digits_hits/detector/include -isystem /home/gy/geant4/src/source/digits_hits/digits/include -isystem /home/gy/geant4/src/source/digits_hits/hits/include -isystem /home/gy/geant4/src/source/digits_hits/scorer/include -isystem /home/gy/geant4/src/source/digits_hits/utils/include -isystem /home/gy/geant4/src/source/error_propagation/include -isystem /home/gy/geant4/src/source/event/include -isystem /home/gy/geant4/src/source/externals/clhep/include -isystem /home/gy/geant4/src/source/externals/zlib/include -isystem /home/gy/geant4/src/source/geometry/biasing/include -isystem /home/gy/geant4/src/source/geometry/divisions/include -isystem /home/gy/geant4/src/source/geometry/magneticfield/include -isystem /home/gy/geant4/build/source/geometry/include -isystem /home/gy/geant4/src/source/geometry/management/include -isystem /home/gy/geant4/src/source/geometry/navigation/include -isystem /home/gy/geant4/src/source/geometry/solids/Boolean/include -isystem /home/gy/geant4/src/source/geometry/solids/CSG/include -isystem /home/gy/geant4/src/source/geometry/solids/specific/include -isystem /home/gy/geant4/src/source/geometry/volumes/include -isystem /home/gy/geant4/src/source/global/HEPGeometry/include -isystem /home/gy/geant4/src/source/global/HEPNumerics/include -isystem /home/gy/geant4/src/source/global/HEPRandom/include -isystem /home/gy/geant4/build/source/global/include -isystem /home/gy/geant4/src/source/global/management/include -isystem /home/gy/geant4/src/source/graphics_reps/include -isystem /home/gy/geant4/src/source/intercoms/include -isystem /home/gy/geant4/src/source/interfaces/GAG/include -isystem /home/gy/geant4/src/source/interfaces/basic/include -isystem /home/gy/geant4/src/source/interfaces/common/include -isystem /home/gy/geant4/src/source/materials/include -isystem /home/gy/geant4/src/source/parameterisations/gflash/include -isystem /home/gy/geant4/src/source/particles/adjoint/include -isystem /home/gy/geant4/src/source/particles/bosons/include -isystem /home/gy/geant4/src/source/particles/hadrons/barions/include -isystem /home/gy/geant4/src/source/particles/hadrons/ions/include -isystem /home/gy/geant4/src/source/particles/hadrons/mesons/include -isystem /home/gy/geant4/src/source/particles/leptons/include -isystem /home/gy/geant4/src/source/particles/management/include -isystem /home/gy/geant4/src/source/particles/shortlived/include -isystem /home/gy/geant4/src/source/particles/utils/include -isystem /home/gy/geant4/src/source/persistency/ascii/include -isystem /home/gy/geant4/src/source/persistency/mctruth/include -isystem /home/gy/geant4/src/source/physics_lists/builders/include -isystem /home/gy/geant4/src/source/physics_lists/constructors/decay/include -isystem /home/gy/geant4/src/source/physics_lists/constructors/electromagnetic/include -isystem /home/gy/geant4/src/source/physics_lists/constructors/factory/include -isystem /home/gy/geant4/src/source/physics_lists/constructors/gamma_lepto_nuclear/include -isystem /home/gy/geant4/src/source/physics_lists/constructors/hadron_elastic/include -isystem /home/gy/geant4/src/source/physics_lists/constructors/hadron_inelastic/include -isystem /home/gy/geant4/src/source/physics_lists/constructors/ions/include -isystem /home/gy/geant4/src/source/physics_lists/constructors/limiters/include -isystem /home/gy/geant4/src/source/physics_lists/constructors/stopping/include -isystem /home/gy/geant4/src/source/physics_lists/lists/include -isystem /home/gy/geant4/src/source/physics_lists/util/include -isystem /home/gy/geant4/src/source/processes/biasing/management/include -isystem /home/gy/geant4/src/source/processes/biasing/generic/include -isystem /home/gy/geant4/src/source/processes/biasing/importance/include -isystem /home/gy/geant4/src/source/processes/cuts/include -isystem /home/gy/geant4/src/source/processes/decay/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/adjoint/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/dna/processes/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/dna/models/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/dna/utils/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/dna/management/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/dna/molecules/management/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/dna/molecules/types/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/highenergy/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/lowenergy/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/muons/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/pii/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/polarisation/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/standard/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/utils/include -isystem /home/gy/geant4/src/source/processes/electromagnetic/xrays/include -isystem /home/gy/geant4/src/source/processes/hadronic/cross_sections/include -isystem /home/gy/geant4/src/source/processes/hadronic/management/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/abla/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/abrasion/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/binary_cascade/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/cascade/cascade/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/coherent_elastic/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/de_excitation/ablation/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/de_excitation/evaporation/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/de_excitation/fermi_breakup/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/de_excitation/fission/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/de_excitation/gem_evaporation/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/de_excitation/handler/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/de_excitation/management/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/de_excitation/multifragmentation/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/de_excitation/photon_evaporation/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/de_excitation/util/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/em_dissociation/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/fission/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/im_r_matrix/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/inclxx/utils/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/inclxx/incl_physics/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/inclxx/interface/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/gamma_nuclear/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/lend/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/lepto_nuclear/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/management/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/particle_hp/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/parton_string/diffraction/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/parton_string/hadronization/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/parton_string/management/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/parton_string/qgsm/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/pre_equilibrium/exciton_model/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/qmd/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/quasi_elastic/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/radioactive_decay/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/rpg/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/theo_high_energy/include -isystem /home/gy/geant4/src/source/processes/hadronic/models/util/include -isystem /home/gy/geant4/src/source/processes/hadronic/processes/include -isystem /home/gy/geant4/src/source/processes/hadronic/stopping/include -isystem /home/gy/geant4/src/source/processes/hadronic/util/include -isystem /home/gy/geant4/src/source/processes/management/include -isystem /home/gy/geant4/src/source/processes/optical/include -isystem /home/gy/geant4/src/source/processes/solidstate/phonon/include -isystem /home/gy/geant4/src/source/processes/solidstate/channeling/include -isystem /home/gy/geant4/src/source/processes/parameterisation/include -isystem /home/gy/geant4/src/source/processes/scoring/include -isystem /home/gy/geant4/src/source/processes/transportation/include -isystem /home/gy/geant4/src/source/readout/include -isystem /home/gy/geant4/src/source/run/include -isystem /home/gy/geant4/src/source/tasking/include -isystem /home/gy/geant4/src/source/track/include -isystem /home/gy/geant4/src/source/tracking/include -isystem /home/gy/geant4/src/source/visualization/FukuiRenderer/include -isystem /home/gy/geant4/src/source/visualization/HepRep/include -isystem /home/gy/geant4/src/source/visualization/RayTracer/include -isystem /home/gy/geant4/src/source/visualization/Tree/include -isystem /home/gy/geant4/src/source/visualization/VRML/include -isystem /home/gy/geant4/src/source/visualization/XXX/include -isystem /home/gy/geant4/src/source/visualization/externals/gl2ps/include -isystem /home/gy/geant4/src/source/visualization/gMocren/include -isystem /home/gy/geant4/src/source/visualization/management/include -isystem /home/gy/geant4/src/source/visualization/modeling/include -isystem /home/gy/geant4/src/source/visualization/OpenGL/include -isystem /home/gy/geant4/src/source/externals/ptl/include -isystem /home/gy/geant4/src/source/externals/zlib/src -isystem /home/gy/geant4/build/source/externals/zlib -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -isystem /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtOpenGL -isystem /usr/include/x86_64-linux-gnu/qt5/QtPrintSupport 

