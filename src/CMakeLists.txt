file(GLOB PROJECTS RELATIVE
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${CMAKE_CURRENT_SOURCE_DIR}/*"
)

foreach (PROJECT_NAME ${PROJECTS})
  set (PROJECT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}")

  if (IS_DIRECTORY ${PROJECT_PATH}) 
    if (EXISTS "${PROJECT_PATH}/CMakeLists.txt")
      # Add the subdirectory
      message("Configuring project \"${PROJECT_NAME}\"...")

      add_subdirectory("${PROJECT_PATH}")
    else()
      # Default configuration
      message("Configuring bundle \"${PROJECT_NAME}\"...")

      file(GLOB_RECURSE PROJECT_PUBLIC
        "${PROJECT_PATH}/include/*.hpp"
      )
      file(GLOB_RECURSE PROJECT_PRIVATE
        "${PROJECT_PATH}/private/*.hpp"
        "${PROJECT_PATH}/private/*.cpp"
      )
      include_directories(
        "${PROJECT_PATH}/include"
        "${PROJECT_PATH}/private"
      )
      add_library(${PROJECT_NAME} SHARED
        ${PROJECT_PUBLIC}
        ${PROJECT_PRIVATE}
      )
      set_target_properties(${PROJECT_NAME}
        PROPERTIES PUBLIC_HEADER "${PROJECT_PUBLIC}"
      )
      install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bundles
        COMPONENT ${PROJECT_NAME}
        PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_PREFIX}/include"
        COMPONENT ${PROJECT_NAME}
      )
    endif()
  endif()  
endforeach()
