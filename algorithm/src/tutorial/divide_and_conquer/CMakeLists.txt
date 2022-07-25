add_executable(FindTwoAdded find_two_added.cxx)

add_executable(FindMaxSubArr find_max_subarr.cxx)

target_include_directories(FindTwoAdded PUBLIC
							"${PROJECT_BINARY_DIR}"
							"${PROJECT_SOURCE_DIR}/lib/sort"
							"${PROJECT_SOURCE_DIR}/lib/divide_and_conquer"
							)

target_include_directories(FindMaxSubArr PUBLIC
							"${PROJECT_BINARY_DIR}"
							"${PROJECT_SOURCE_DIR}/lib/sort"
							"${PROJECT_SOURCE_DIR}/lib/divide_and_conquer"
							)
