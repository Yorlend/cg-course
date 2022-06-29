cmake_minimum_required(VERSION 3.0.0)
project(fluidsim VERSION 0.1.0)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0)

add_subdirectory(src)
