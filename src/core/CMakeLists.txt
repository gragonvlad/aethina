file(GLOB_RECURSE PROJECT_PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
)
file(GLOB_RECURSE PROJECT_PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/private/*.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/private/*.cpp"
)
include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}/private"
)
add_library(core SHARED
  ${PROJECT_PUBLIC}
  ${PROJECT_PRIVATE}
)
add_dependencies(${PROJECT_NAME}
  config
)
target_link_libraries(core
  ${AETHINA_LINK_LIBRARIES}
)
set_target_properties(core
  PROPERTIES PUBLIC_HEADER "${PROJECT_PUBLIC}"
)

install(TARGETS core
  RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
  PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_PREFIX}/include"
)
