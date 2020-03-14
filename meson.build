project('qt-app', 'cpp', default_options: ['cpp_std=c++17'])

qt_deps = dependency('qt5', modules: ['Widgets'])

sources = [
    'src/main.cpp',
    'src/main_window.cpp',
]

includes = include_directories(
    'include',
)

executable(
    'main',
    sources,
    include_directories: includes,
    dependencies: [qt_deps],
)
