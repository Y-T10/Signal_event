cmake_minimum_required(VERSION 3.28.3)

project(sig_event VERSION 0.0.0 LANGUAGES CXX)

# ビルド周りの設定
option(BUILD_SHARED_LIBS "Build shared libraries." OFF)
option(CMAKE_BUILD_TYPE "Build type." Release)
option(BUILD_TESTING "Building tests." OFF)

# インストール周りの設定
option(CMAKE_INSTALL_PREFIX "Install prefix." "$ENV{HOME}/.local")

# CMAKE_EXPORT_COMPILE_COMMANDSの既定値を設定する
if ((NOT (DEFINED $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})) AND (DEFINED CMAKE_EXPORT_COMPILE_COMMANDS))
  set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
endif()

#ライブラリを追加
add_library(sig_event)

#プログラムファイルを追加
# - ${CMAKE_CURRENT_SOURCE_DIR}: このファイルがあるディレクトリ
target_sources(sig_event PRIVATE sig_event.cpp)
target_include_directories(sig_event PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#ライブラリを追加
#target_link_libraries(sig_event PRIVATE)
