cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)

include_directories(
    term
    term/navigator
    term/termin
    term/termout
    utils/utf
    utils/utf/utfcpp/source
    utils/utf/utfcpp/source/utf8
    utils/ansi
    utils/aart
    utils/frame
    utils/txtutils
    )
    
add_executable(colors
    main.cpp
    term/term.cpp
    term/navigator/navigator.cpp
    term/termin/termin.cpp
    term/termout/termout.cpp
    utils/utf/utf.cpp
    utils/aart/aart.cpp
    utils/frame/frame.cpp
    utils/txtutils/txtutils.cpp
)
