# The ORDER of every setting is really important...

cmake_minimum_required(VERSION 3.20)

project(NVI VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(NVI main.cxx)

add_subdirectory(tpm)
add_subdirectory(strategy)
add_subdirectory(fun_obj)
add_subdirectory(classic_strategy)

target_link_libraries(NVI PUBLIC ExTpm
								 ExStgy
								 ExFobj
								 ExCstgy)


target_include_directories(NVI PUBLIC
							"${PROJECT_BINARY_DIR}"
							"${PROJECT_SOURCE_DIR}/tpm"
							"${PROJECT_SOURCE_DIR}/strategy"
							"${PROJECT_SOURCE_DIR}/fun_obj"
							"${PROJECT_SOURCE_DIR}/classic_strategy"
							)
