file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)


set(SRC_FILES ${PROJECT_SOURCE_DIR}/src/dean.cpp
              ${PROJECT_SOURCE_DIR}/src/student.cpp
              ${PROJECT_SOURCE_DIR}/src/group.cpp)
set(SRC_FILES ${PROJECT_SOURCE_DIR}/src/Deanery.cpp
              ${PROJECT_SOURCE_DIR}/src/Student.cpp
              ${PROJECT_SOURCE_DIR}/src/Group.cpp)

set(CMAKE_CXX_STANDARD 11)

@@ -71,4 +71,4 @@ if (BUILD_TESTS)
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
  endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"

endif() 
endif()