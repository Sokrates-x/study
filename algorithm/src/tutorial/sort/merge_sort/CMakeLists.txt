add_executable(MergeSort merge_sort.cxx)

target_include_directories(MergeSort PUBLIC
							"${PROJECT_BINARY_DIR}"
							"${PROJECT_SOURCE_DIR}/lib/sort"
							)	
