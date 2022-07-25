add_executable(InsertSort insert_sort.cxx)

target_include_directories(InsertSort PUBLIC
							"${PROJECT_BINARY_DIR}"
							"${PROJECT_SOURCE_DIR}/lib/sort"
							)	
