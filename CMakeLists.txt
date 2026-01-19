cmake_minimum_required(VERSION 4.1)
project(noc)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)
set(SFML_LIBRARIES SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System)

add_executable(0_Randomness_Walker 0_randomness/Walker.cpp)
target_link_libraries(0_Randomness_Walker PRIVATE ${SFML_LIBRARIES})

add_executable(0_Random_Distribution 0_randomness/random_distribution.cpp)
target_link_libraries(0_Random_Distribution PRIVATE ${SFML_LIBRARIES})

add_executable(0_Skewed_Random_Distribution 0_randomness/skewed_random_walker.cpp)
target_link_libraries(0_Skewed_Random_Distribution PRIVATE ${SFML_LIBRARIES})

add_executable(0_Random_Walk_Tends_To_Right 0_randomness/random_walk_tends_to_right.cpp)
target_link_libraries(0_Random_Walk_Tends_To_Right PRIVATE ${SFML_LIBRARIES})

add_executable(0_exercise_3 0_randomness/exercise_3.cpp)
target_link_libraries(0_exercise_3 PRIVATE ${SFML_LIBRARIES})