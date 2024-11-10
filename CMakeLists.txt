cmake_minimum_required(VERSION 3.26.0)
project(strava__)

set(CMAKE_CXX_STANDARD 20)

if ((CMAKE_CXX_COMPILER_ID MATCHES "Clang") OR ((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") AND NOT (MINGW)))

    message(STATUS "Your compiler is ${CMAKE_CXX_COMPILER_ID}!")

    # should be using GCC or CLANG

    # Both, GCC and Clang support the same option set
    # We first turn on Warnings
    # --> https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
    #
    # -Wall stands for All Warnings
    # -Wextra pushes that a bit further
    # -pedantic sets the compiler to use strict ISO C++
    # -Werror treats all warnings as errors so you have to fix them
    #   add_compile_options(-Wall -Wextra -pedantic) # -Werror)
    #
    # Sanitizer options
    # The following will turn on Debugging (-g flag) and the Address Sanitizer
    # which is turned on with the -fsanitize=address option to the compiler.
    add_compile_options(-Wall -Wextra -pedantic -fsanitize=address,undefined -g)

    # When we turn on the sanitizer, you also need to instruct the
    # linker that it will be used which happens with the following
    # link option command.
    add_link_options(-fsanitize=address,undefined -g)

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
    # MSVC uses a different warning flags
    add_compile_options(/W4)  # shut off warnings as errors, which is the /Wx option
    add_compile_options(/fsanitize=address)

endif()

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "-DCMAKE_TOOLCHAIN_FILE=C:/Users/alexh/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")


#Include curl
find_package(CURL REQUIRED)
message("curl libs: ${CURL_LIBRARIES}")
message("curl dirs: ${CURL_INCLUDE_DIRS}")
if (NOT CURL_FOUND)
    message("Could not locate curl. Please install or add to your system's PATH")
endif (NOT CURL_FOUND)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)

FetchContent_MakeAvailable(json)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.5.2
)

FetchContent_MakeAvailable(Catch2)

# Specify the paths to the library and include directories for curl
##include_directories("~/dev/curl/curl-8.11.0/include")
##link_directories("~/dev/curl/curl-8.11.0/lib")

include_directories(${PROJECT_SOURCE_DIR} # for includiing headers in test files
        ${CURL_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/tests
        ${PROJECT_SOURCE_DIR}/authorization)

add_library(strava__lib main.cpp
        tests/curl_test.cpp
        tests/strava_api_test.cpp
        tests/strava_activity_test.cpp
        Activity.cpp
        Activity.h
        CurlRequests.cpp
        CurlRequests.h
        StravaURLs.cpp
        StravaURLs.h
        authorization/AuthorizationTokens.cpp
        authorization/AuthorizationTokens.h
        ActivityStorage.cpp
        ActivityStorage.h
        tests/nlohmann_test.cpp
)

target_link_libraries(strava__lib PRIVATE CURL::libcurl
        nlohmann_json::nlohmann_json)

add_executable(strava__ main.cpp
        Activity.cpp
        Activity.h
        CurlRequests.cpp
        CurlRequests.h
        StravaURLs.cpp
        StravaURLs.h
        authorization/AuthorizationTokens.cpp
        authorization/AuthorizationTokens.h
        ActivityStorage.cpp
        ActivityStorage.h
)
add_executable(curlTest tests/curl_test.cpp
        tests/strava_api_test.cpp
        Activity.cpp
        Activity.h
        CurlRequests.cpp
        CurlRequests.h
        StravaURLs.cpp
        StravaURLs.h
        authorization/AuthorizationTokens.cpp
        authorization/AuthorizationTokens.h
        ActivityStorage.cpp
        ActivityStorage.h
)
add_executable(stravaApiTest tests/strava_api_test.cpp
        Activity.cpp
        Activity.h
        CurlRequests.cpp
        CurlRequests.h
        StravaURLs.cpp
        StravaURLs.h
        authorization/AuthorizationTokens.cpp
        authorization/AuthorizationTokens.h
        ActivityStorage.cpp
        ActivityStorage.h
)
add_executable(stravaAcitvityTest tests/strava_activity_test.cpp
        Activity.cpp
        Activity.h
        CurlRequests.cpp
        CurlRequests.h
        StravaURLs.cpp
        StravaURLs.h
        authorization/AuthorizationTokens.cpp
        authorization/AuthorizationTokens.h
        ActivityStorage.cpp
        ActivityStorage.h
)

target_link_libraries(strava__ PRIVATE CURL::libcurl)
target_link_libraries(curlTest PRIVATE CURL::libcurl)
target_link_libraries(stravaApiTest PRIVATE ${CURL_LIBRARIES})
target_link_libraries(stravaAcitvityTest PRIVATE ${CURL_LIBRARIES})

add_executable(nlohmannTest tests/nlohmann_test.cpp
        Activity.cpp
        Activity.h
        CurlRequests.cpp
        CurlRequests.h
        StravaURLs.cpp
        StravaURLs.h
        authorization/AuthorizationTokens.cpp
        authorization/AuthorizationTokens.h
        ActivityStorage.cpp
        ActivityStorage.h)

target_link_libraries(nlohmannTest PRIVATE nlohmann_json::nlohmann_json
                CURL::libcurl)

