cmake_minimum_required(VERSION 3.6)
project(Salary_Calculator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp core/Calculator.cpp core/Calculator.h core/Deduction.cpp core/Deduction.h core/IncomeTax.cpp core/IncomeTax.h core/SocialSecurityTax.cpp core/SocialSecurityTax.h)
add_executable(Salary_Calculator ${SOURCE_FILES})