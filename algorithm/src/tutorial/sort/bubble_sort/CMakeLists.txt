add_executable(BubbleSort bubble_sort.cxx)

target_include_directories(BubbleSort PUBLIC
							"${PROJECT_BINARY_DIR}"
							"${PROJECT_SOURCE_DIR}/lib/sort"
							)	
