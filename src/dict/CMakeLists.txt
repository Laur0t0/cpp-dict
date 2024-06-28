add_library(dict dict.cpp)
target_link_libraries(dict node)

RESY_ADD_INLINE_TESTS(
    SRC_FILE_STEM dict
    TEST_CASES
      empty
      insert
    LIBRARIES
      node
)
