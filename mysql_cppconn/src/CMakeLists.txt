cmake_minimum_required(VERSION 3.10)

project(MySQL_CppConn VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MySQL_CppConn mysql_cpp_conn.cxx)

target_include_directories(MySQL_CppConn PUBLIC
							"${PROJECT_BINARY_DIR}"
							"${PROJECT_SOURCE_DIR}"
							/usr/include/mysql-cppconn/mysql/
							)

target_link_libraries(MySQL_CppConn PUBLIC
							"/lib64/libmysqlcppconn.so"
					 	)
