#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
#

cmake_minimum_required(VERSION 2.6)

include_directories(../../libminifi/include  ../../libminifi/include/core/yaml  ../../libminifi/include/core  ../../thirdparty/spdlog-20170710/include ../../thirdparty/concurrentqueue ../../thirdparty/yaml-cpp-yaml-cpp-0.5.3/include ${CIVET_THIRDPARTY_ROOT}/include ../../thirdparty/) 

find_package(LibGPS REQUIRED)

include_directories(${LIBGPS_INCLUDE_DIRS})

file(GLOB SOURCES  "*.cpp")

add_library(minifi-gps STATIC ${SOURCES})
set_property(TARGET minifi-gps PROPERTY POSITION_INDEPENDENT_CODE ON)
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(PUBLIC minifi-gps "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(minifi-gps "${CMAKE_THREAD_LIBS_INIT}")
endif()


# Include UUID
find_package(UUID REQUIRED)
target_link_libraries(minifi-gps ${LIBMINIFI} ${UUID_LIBRARIES} ${LIBGPS_LIBRARIES})
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
target_link_libraries(minifi-gps ${CMAKE_DL_LIBS} )
find_package(ZLIB REQUIRED)
include_directories(${ZLIB_INCLUDE_DIRS})
target_link_libraries (minifi-gps ${ZLIB_LIBRARIES})
if (WIN32)
    set_target_properties(minifi-gps PROPERTIES
        LINK_FLAGS "/WHOLEARCHIVE"
    )
elseif (APPLE)
    set_target_properties(minifi-gps PROPERTIES
        LINK_FLAGS "-Wl,-all_load"
    )
else ()
    set_target_properties(minifi-gps PROPERTIES
        LINK_FLAGS "-Wl,--whole-archive"
    )
endif ()


SET (GPS-EXTENSION minifi-gps PARENT_SCOPE)

register_extension(minifi-gps)
