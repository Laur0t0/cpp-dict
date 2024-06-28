add_library(node node.cpp)

RESY_ADD_INLINE_TESTS(
    SRC_FILE_STEM node
    TEST_CASES
      empty_node
      nonempty_node
      set
      insert
      find
)
