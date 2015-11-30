include_directories(
  "${CMAKE_BINARY_DIR}"
)

file(GLOB PROJECTS RELATIVE
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${CMAKE_CURRENT_SOURCE_DIR}/*"
)

# Forward include the public headers of every project
foreach (PROJECT_NAME ${PROJECTS})
  if (IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/include")
    include_directories(
      "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/include"
    )
  endif()
endforeach()

# Create the bundles or add the subdirectories
foreach (PROJECT_NAME ${PROJECTS})
  set (PROJECT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}")

  if (IS_DIRECTORY ${PROJECT_PATH}) 
    message(STATUS "Configuring \"${PROJECT_NAME}\"...")
  
    if (EXISTS "${PROJECT_PATH}/CMakeLists.txt")
      # Add the subdirectory
      add_subdirectory("${PROJECT_PATH}")
    else()
      # Default configuration
      file(GLOB_RECURSE PROJECT_PUBLIC
        "${PROJECT_PATH}/include/*.hpp"
      )
      file(GLOB_RECURSE PROJECT_PRIVATE
        "${PROJECT_PATH}/private/*.hpp"
        "${PROJECT_PATH}/private/*.cpp"
      )
      include_directories(
        "${PROJECT_PATH}/private"
      )
      add_library(${PROJECT_NAME} SHARED
        ${PROJECT_PUBLIC}
        ${PROJECT_PRIVATE}
      )
      add_dependencies(${PROJECT_NAME}
        config
      )
      target_link_libraries(${PROJECT_NAME}
        ${AETHINA_LINK_LIBRARIES}
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
