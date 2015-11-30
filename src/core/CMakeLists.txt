file(GLOB_RECURSE PROJECT_PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
)
file(GLOB_RECURSE PROJECT_PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/private/*.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/private/*.cpp"
)
file(GLOB_RECURSE PROJECT_CONFIG
  "${CMAKE_CURRENT_SOURCE_DIR}/conf/*.json"
)
include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/private"
)

if (MSVC)
  set(PROJECT_RESOURCES
    resources/aethina.rc
    resources/aethina.ico
  )
endif()

add_executable(aethina
  ${PROJECT_PUBLIC}
  ${PROJECT_PRIVATE}
  ${PROJECT_CONFIG}
  ${PROJECT_RESOURCES}
)
set_target_properties(aethina
  PROPERTIES PUBLIC_HEADER "${PROJECT_PUBLIC}"
)
install(TARGETS aethina
  DESTINATION "${CMAKE_INSTALL_PREFIX}"
  PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_PREFIX}/include"
)
# Install the config file when it doesn't exist
install(CODE "
  if (NOT EXISTS \"${CMAKE_INSTALL_PREFIX}/aethina.json\")
    file(INSTALL \"${CMAKE_CURRENT_SOURCE_DIR}/conf/aethina.json\"
      DESTINATION \"${CMAKE_INSTALL_PREFIX}\"
    )
  endif()
")
