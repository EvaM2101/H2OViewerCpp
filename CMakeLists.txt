cmake_minimum_required(VERSION 3.15)
project(modelH2Opropre)

set(CMAKE_CXX_STANDARD 11)

# lib sfml
include_directories(C:/sfml/SFML-2.5.1/include)
link_directories(C:/sfml/SFML-2.5.1/lib)

add_executable(modelH2Opropre src/main.cpp src/model/sdd/vector3d.hpp src/model/elements/atome.cpp src/model/elements/atome.hpp src/model/elements/moleculeH2O.cpp src/model/elements/moleculeH2O.hpp src/controller/chargeur/chargeur_molecules.cpp src/controller/chargeur/chargeur_molecules.hpp src/model/elements/boite.cpp src/model/elements/boite.hpp src/model/elements/simulation.cpp src/model/elements/simulation.hpp src/model/constantes/constantes.cpp src/model/constantes/constantes.hpp src/model/sdd/matrix.hpp src/model/projection/matrice_projection.cpp src/model/projection/matrice_projection.hpp src/view/application.cpp src/view/application.hpp src/controller/manager/simulation_manager.cpp src/controller/manager/simulation_manager.hpp src/controller/selectionneur/selectionneur_molecules.cpp src/controller/selectionneur/selectionneur_molecules.hpp src/controller/projecteur/projecteur.cpp src/controller/projecteur/projecteur.hpp src/view/dessinateur/dessinateur.cpp src/view/dessinateur/dessinateur.hpp)
target_link_libraries(modelH2Opropre -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio)