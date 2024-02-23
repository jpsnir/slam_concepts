cmake_minimum_required(VERSION 3.10)
project(slam_concepts)
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)

if(${Eigen3_FOUND})
    message(STATUS "Eigen found : ${Eigen3_VERSION}")
endif()

if(${OpenCV_FOUND})
    message(STATUS "OpenCV found : ${OpenCV_VERSION}")
endif()


if(${Boost_FOUND})
    message(STATUS "Boost found : ${Boost_VERSION}")
endif()


include_directories(${Boost_INCLUDE_DIRS}
                    ${Eigen_INCLUDE_DIRS}
                    ${OpenCV_INCLUDE_DIRS})

add_executable(transformations_1 ./src/transformations_1.cpp)
target_link_libraries(transformations_1 Eigen3::Eigen )

add_executable(transformations_2 ./src/transformations_2.cpp)
target_link_libraries(transformations_2 Eigen3::Eigen )

add_executable(eigen_matrices ./src/eigen_matrices.cpp)
target_link_libraries(transformations_1 Eigen3::Eigen )