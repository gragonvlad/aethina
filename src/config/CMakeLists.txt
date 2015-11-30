add_custom_target(config ALL
  COMMAND "${CMAKE_COMMAND}" -DBUILDDIR="${CMAKE_BINARY_DIR}" -P "${CMAKE_SOURCE_DIR}/src/config/create_config.cmake" "${CMAKE_BINARY_DIR}"
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/aethina_config.hpp.in.cmake"
)

set(SOURCE_FILE "${CMAKE_BINARY_DIR}/aethina_config.hpp")
set(TARGET_FILE "${CMAKE_INSTALL_PREFIX}/include/aethina_config.hpp")

# Install the config when it has changed
install(CODE "
  file(INSTALL \"${SOURCE_FILE}\"
      DESTINATION \"${CMAKE_INSTALL_PREFIX}/include\"
  )
")
