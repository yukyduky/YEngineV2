# CMake generated Testfile for 
# Source directory: D:/OneDrive/Dokument/repos/YEngine/tests/tests
# Build directory: D:/OneDrive/Dokument/repos/YEngine/tests/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(tests "D:/OneDrive/Dokument/repos/YEngine/tests/tests/Debug/tests.exe")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(tests "D:/OneDrive/Dokument/repos/YEngine/tests/tests/Release/tests.exe")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(tests "D:/OneDrive/Dokument/repos/YEngine/tests/tests/MinSizeRel/tests.exe")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(tests "D:/OneDrive/Dokument/repos/YEngine/tests/tests/RelWithDebInfo/tests.exe")
else()
  add_test(tests NOT_AVAILABLE)
endif()
