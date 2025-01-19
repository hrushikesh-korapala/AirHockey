# Use CCache to speed up compilation by default
if(NOT DEFINED USE_CCACHE)
    set(USE_CCACHE ON)
endif()

include(CPM)

CPMAddPackage(
  NAME Ccache.cmake
  GITHUB_REPOSITORY TheLartians/Ccache.cmake
  VERSION 1.2.5
)