if (NOT BUILDDIR)
  message(FATAL_ERROR "No build dir! Create a ticket.")
endif()

set(SOURCE_FILE_PATH "${CMAKE_SOURCE_DIR}/src/config/aethina_config.hpp.in.cmake")
set(TARGET_FILE_PATH "${BUILDDIR}/aethina_config.hpp")

file(SHA1 "${SOURCE_FILE_PATH}" SOURCE_FILE_CHECKSUM)

# message("${SOURCE_FILE_CHECKSUM} == ${SOURCE_FILE_CHECKSUM_CACHED}")

if (NOT EXISTS "${TARGET_FILE_PATH}" OR
    NOT "${SOURCE_FILE_CHECKSUM}" STREQUAL "${SOURCE_FILE_CHECKSUM_CACHED}")

  # message("Reconfiguring ${SOURCE_FILE_PATH}...")

  configure_file(
    "${CMAKE_SOURCE_DIR}/src/config/aethina_config.hpp.in.cmake"
    "${BUILDDIR}/aethina_config.hpp"
  )

  set(SOURCE_FILE_CHECKSUM_CACHED "${SOURCE_FILE_CHECKSUM}"
      CACHE INTERNAL "Cached config checksum"
  )
endif()
