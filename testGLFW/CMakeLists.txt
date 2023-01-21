add_executable(testGLFW testGLFW.cpp)
target_link_libraries(testGLFW ${CORE})

add_executable(clickTestGLFW clickTestGLFW.cpp)
target_link_libraries(clickTestGLFW ${CORE})

add_executable(positionTestGLFW positionTestGLFW.cpp)
target_link_libraries(positionTestGLFW ${CORE})