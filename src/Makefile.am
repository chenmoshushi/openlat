DIST_SUBDIRS = lib bin test
SUBDIRS = lib bin
if MAKE_TEST 
 SUBDIRS += test
endif

#AM_CPPFLAGS = $(WARNING_CXXFLAGS) $(COMPILANCE_CXXFLAGS) 
#AM_LDFLAGS = -avoid-version -module -shared -export-dynamic -lltdl
#
#BUILT_SOURCES = lex.htk.cpp yacc.htk.cpp yacc.htk.hpp
#CLEANFILES    = lex.htk.cpp yacc.htk.cpp yacc.htk.hpp yacc.htk.report
#
## yacc flags
#AM_YFLAGS = --report=all 
## lex flags
#AM_LFLAGS =
#
#include_HEADERS = 
#
#lib_LTLIBRARIES = openlat.la
#
#openlat_la_SOURCES  = lex.htk.cpp yacc.htk.c
#
#bin_PROGRAMS = demo 
#demo_SOURCES = demo.cpp
#
#yacc.htk.cpp yacc.htk.hpp: htk.y
#	$(YACC) $(YFLAGS) $(AM_YFLAGS) --output=yacc.htk.cpp --defines=yacc.htk.hpp htk.y --report-file=yacc.htk.report 
#
#lex.htk.o: lex.htk.cpp
#	$(GCC)  $(CXXFLAGS) $(AM_CXXFLAGS) -c -o lex.htk.o lex.htk.cpp
#
#lex.htk.cpp: htk.l
#	$(LEX) $(LFLAGS) $(AM_LFLAGS) --outfile=lex.htk.cpp htk.l 

includedir = $(prefix)/include/$(PACKAGE)
include_HEADERS = include/openlat/rmprefix.h include/openlat/iofilter.h include/openlat/approx-shortest-distance.h include/openlat/rmarc.h include/openlat/query.h include/openlat/approx-shortest-path.h include/openlat/vector-weight.h include/openlat/htk-compiler.h include/openlat/utils.h include/openlat/verify.h include/openlat/compat.h include/openlat/normalize.h include/openlat/interactive-sequence-labeling.h
