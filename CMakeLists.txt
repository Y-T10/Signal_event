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

## ライブラリターゲットの定義
add_library(${PROJECT_NAME})
add_library("${PROJECT_NAME}::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

## ターゲットのコンパイルオプションの設定
target_compile_options(${PROJECT_NAME} PRIVATE -Wall $<$<CONFIG:Debug>:-g3>)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_SCAN_FOR_MODULES OFF)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

#プログラムファイルを追加
# - ${CMAKE_CURRENT_SOURCE_DIR}: このファイルがあるディレクトリ
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(${PROJECT_NAME} PRIVATE src/sig_event.cpp)
