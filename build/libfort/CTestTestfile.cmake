# CMake generated Testfile for 
# Source directory: C:/Users/ACER USER5949486/Desktop/CPP-project/libfort
# Build directory: C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_test_dev]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/tests/Debug/libfort_test_dev.exe")
  set_tests_properties([=[libfort_test_dev]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_test_dev]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/tests/Release/libfort_test_dev.exe")
  set_tests_properties([=[libfort_test_dev]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_test_dev]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/tests/MinSizeRel/libfort_test_dev.exe")
  set_tests_properties([=[libfort_test_dev]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_test_dev]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/tests/RelWithDebInfo/libfort_test_dev.exe")
  set_tests_properties([=[libfort_test_dev]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_test_dev]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_test_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/tests/Debug/libfort_test_cpp.exe")
  set_tests_properties([=[libfort_test_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_test_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/tests/Release/libfort_test_cpp.exe")
  set_tests_properties([=[libfort_test_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_test_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/tests/MinSizeRel/libfort_test_cpp.exe")
  set_tests_properties([=[libfort_test_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_test_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/tests/RelWithDebInfo/libfort_test_cpp.exe")
  set_tests_properties([=[libfort_test_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_test_cpp]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_test]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/tests/Debug/libfort_test.exe")
  set_tests_properties([=[libfort_test]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_test]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/tests/Release/libfort_test.exe")
  set_tests_properties([=[libfort_test]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_test]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/tests/MinSizeRel/libfort_test.exe")
  set_tests_properties([=[libfort_test]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_test]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/tests/RelWithDebInfo/libfort_test.exe")
  set_tests_properties([=[libfort_test]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_test]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_simple_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_simple_table.exe")
  set_tests_properties([=[libfort_simple_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_simple_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_simple_table.exe")
  set_tests_properties([=[libfort_simple_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_simple_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_simple_table.exe")
  set_tests_properties([=[libfort_simple_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_simple_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_simple_table.exe")
  set_tests_properties([=[libfort_simple_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_simple_table]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_custom_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_custom_table.exe")
  set_tests_properties([=[libfort_custom_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_custom_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_custom_table.exe")
  set_tests_properties([=[libfort_custom_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_custom_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_custom_table.exe")
  set_tests_properties([=[libfort_custom_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_custom_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_custom_table.exe")
  set_tests_properties([=[libfort_custom_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_custom_table]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_fill_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_fill_table.exe")
  set_tests_properties([=[libfort_fill_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_fill_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_fill_table.exe")
  set_tests_properties([=[libfort_fill_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_fill_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_fill_table.exe")
  set_tests_properties([=[libfort_fill_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_fill_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_fill_table.exe")
  set_tests_properties([=[libfort_fill_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_fill_table]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_custom_border_style]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_custom_border_style.exe")
  set_tests_properties([=[libfort_custom_border_style]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_custom_border_style]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_custom_border_style.exe")
  set_tests_properties([=[libfort_custom_border_style]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_custom_border_style]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_custom_border_style.exe")
  set_tests_properties([=[libfort_custom_border_style]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_custom_border_style]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_custom_border_style.exe")
  set_tests_properties([=[libfort_custom_border_style]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_custom_border_style]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_print_styles]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_print_styles.exe")
  set_tests_properties([=[libfort_print_styles]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_print_styles]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_print_styles.exe")
  set_tests_properties([=[libfort_print_styles]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_print_styles]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_print_styles.exe")
  set_tests_properties([=[libfort_print_styles]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_print_styles]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_print_styles.exe")
  set_tests_properties([=[libfort_print_styles]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_print_styles]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_math_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_math_table.exe")
  set_tests_properties([=[libfort_math_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_math_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_math_table.exe")
  set_tests_properties([=[libfort_math_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_math_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_math_table.exe")
  set_tests_properties([=[libfort_math_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_math_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_math_table.exe")
  set_tests_properties([=[libfort_math_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_math_table]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_beautiful_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_beautiful_table.exe")
  set_tests_properties([=[libfort_beautiful_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_beautiful_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_beautiful_table.exe")
  set_tests_properties([=[libfort_beautiful_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_beautiful_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_beautiful_table.exe")
  set_tests_properties([=[libfort_beautiful_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_beautiful_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_beautiful_table.exe")
  set_tests_properties([=[libfort_beautiful_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_beautiful_table]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_complex_layout]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_complex_layout.exe")
  set_tests_properties([=[libfort_complex_layout]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_complex_layout]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_complex_layout.exe")
  set_tests_properties([=[libfort_complex_layout]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_complex_layout]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_complex_layout.exe")
  set_tests_properties([=[libfort_complex_layout]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_complex_layout]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_complex_layout.exe")
  set_tests_properties([=[libfort_complex_layout]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_complex_layout]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_non_ascii_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_non_ascii_table.exe")
  set_tests_properties([=[libfort_non_ascii_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_non_ascii_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_non_ascii_table.exe")
  set_tests_properties([=[libfort_non_ascii_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_non_ascii_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_non_ascii_table.exe")
  set_tests_properties([=[libfort_non_ascii_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_non_ascii_table]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_non_ascii_table.exe")
  set_tests_properties([=[libfort_non_ascii_table]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_non_ascii_table]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_simple_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_simple_table_cpp.exe")
  set_tests_properties([=[libfort_simple_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_simple_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_simple_table_cpp.exe")
  set_tests_properties([=[libfort_simple_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_simple_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_simple_table_cpp.exe")
  set_tests_properties([=[libfort_simple_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_simple_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_simple_table_cpp.exe")
  set_tests_properties([=[libfort_simple_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_simple_table_cpp]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_custom_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_custom_table_cpp.exe")
  set_tests_properties([=[libfort_custom_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_custom_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_custom_table_cpp.exe")
  set_tests_properties([=[libfort_custom_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_custom_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_custom_table_cpp.exe")
  set_tests_properties([=[libfort_custom_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_custom_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_custom_table_cpp.exe")
  set_tests_properties([=[libfort_custom_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_custom_table_cpp]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_complex_layout_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_complex_layout_cpp.exe")
  set_tests_properties([=[libfort_complex_layout_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_complex_layout_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_complex_layout_cpp.exe")
  set_tests_properties([=[libfort_complex_layout_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_complex_layout_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_complex_layout_cpp.exe")
  set_tests_properties([=[libfort_complex_layout_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_complex_layout_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_complex_layout_cpp.exe")
  set_tests_properties([=[libfort_complex_layout_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_complex_layout_cpp]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_fill_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_fill_table_cpp.exe")
  set_tests_properties([=[libfort_fill_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_fill_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_fill_table_cpp.exe")
  set_tests_properties([=[libfort_fill_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_fill_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_fill_table_cpp.exe")
  set_tests_properties([=[libfort_fill_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_fill_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_fill_table_cpp.exe")
  set_tests_properties([=[libfort_fill_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_fill_table_cpp]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_beautiful_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_beautiful_table_cpp.exe")
  set_tests_properties([=[libfort_beautiful_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_beautiful_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_beautiful_table_cpp.exe")
  set_tests_properties([=[libfort_beautiful_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_beautiful_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_beautiful_table_cpp.exe")
  set_tests_properties([=[libfort_beautiful_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_beautiful_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_beautiful_table_cpp.exe")
  set_tests_properties([=[libfort_beautiful_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_beautiful_table_cpp]=] NOT_AVAILABLE)
endif()
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[libfort_non_ascii_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Debug/libfort_non_ascii_table_cpp.exe")
  set_tests_properties([=[libfort_non_ascii_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[libfort_non_ascii_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/Release/libfort_non_ascii_table_cpp.exe")
  set_tests_properties([=[libfort_non_ascii_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[libfort_non_ascii_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/MinSizeRel/libfort_non_ascii_table_cpp.exe")
  set_tests_properties([=[libfort_non_ascii_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[libfort_non_ascii_table_cpp]=] "C:/Users/ACER USER5949486/Desktop/CPP-project/build/libfort/examples/RelWithDebInfo/libfort_non_ascii_table_cpp.exe")
  set_tests_properties([=[libfort_non_ascii_table_cpp]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;265;add_test;C:/Users/ACER USER5949486/Desktop/CPP-project/libfort/CMakeLists.txt;0;")
else()
  add_test([=[libfort_non_ascii_table_cpp]=] NOT_AVAILABLE)
endif()
subdirs("lib")
subdirs("src")
subdirs("tests")
subdirs("examples")
