cmake_minimum_required(VERSION 3.2)

PROJECT(dmmagicenum)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

SET(DMMAGICENUM_VERSION_MAJOR "1")
SET(DMMAGICENUM_VERSION_MINOR "0")
SET(DMMAGICENUM_VERSION_PATCH "1")
SET(DMMAGICENUM_VERSION "${DMMAGICENUM_VERSION_MAJOR}.${DMMAGICENUM_VERSION_MINOR}.${DMMAGICENUM_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMMAGICENUM_VERSION}")

OPTION(USE_DMMAGICENUM "use dmmagicenum" OFF)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/dmmagicenum_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/dmmagicenum_config.h)

ModuleImportAll("thirdparty")
LibImport("dmmagicenum_module" "src/dmmagicenum_module")
ExeImport("test" "dmmagicenum_module")

#ADD_CUSTOM_COMMAND(
#TARGET dmmagicenumtest
#PRE_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_if_different
#${CMAKE_CURRENT_SOURCE_DIR}/config/test.csv
#$<TARGET_FILE_DIR:dmmagicenumtest>
#)

#INSTALL(DIRECTORY include/ DESTINATION include)
#INSTALL(TARGETS dmmagicenum
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)

#SET(DMMAGICENUM_LIBS "dmmagicenum")
#MARK_AS_ADVANCED(${DMMAGICENUM_LIBS})