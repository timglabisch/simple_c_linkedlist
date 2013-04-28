cmake_minimum_required (VERSION 2.6)

project (lst)
add_executable(lst main.c)

project (blst)
add_executable(blst main_better.c)


# compiler flags
set(CMAKE_C_FLAGS "-O9 -march=native -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include")
set(CMAKE_C_FLAGS_RELEASE "-O9 -march=native -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include")

set(CMAKE_C_FLAGS_DEBUG "-O0 -g -pg -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include")

# distclean
ADD_CUSTOM_TARGET (distclean @echo cleaning for source distribution)
SET(DISTCLEANED
	cmake.depends
	cmake.check_depends
	CMakeCache.txt
	cmake.check_cache
	*.cmake
	Makefile
	core core.*
	gmon.out
	*~
	CMakeFiles
)

ADD_CUSTOM_COMMAND(
	DEPENDS clean
	COMMENT "distribution clean"
	COMMAND rm
	ARGS    -Rf CMakeTmp ${DISTCLEANED}
	TARGET  distclean
)