aux_source_directory(. STANDARD_FILES)
add_library(standard ${STANDARD_FILES})

target_include_directories(standard
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )