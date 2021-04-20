
include(FetchContent)

set(RILEY_CPP_UTILS_WITH_TESTS OFF)
FetchContent_Declare(
	RileyCppUtils
	GIT_REPOSITORY https://github.com/ryantherileyman/riley-cpp-utils.git
	GIT_TAG origin/feature/string-split
)
FetchContent_MakeAvailable(RileyCppUtils)
