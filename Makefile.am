## Makefile.am -- Process this file with automake to produce Makefile.in
AM_CPPFLAGS=-I include/
LIBS = -lmysqlclient

bin_PROGRAMS = pharma
pharma_SOURCES = src/main.cpp src/PharmaProduct.cpp src/PharmaTransaction.cpp 

dist_pkgdata_DATA = bootstrap.sh configure.ac pharma.sql Doxyfile Makefile.am README.md docs/
