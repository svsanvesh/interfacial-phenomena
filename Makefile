# the default CFLAGS are set in $(BASILISK)/config
CFLAGS += -O2 -fopenmp

all: check

karman-sv.c: karman.c
	ln -s karman.c karman-sv.c
karman-sv.tst: karman.s

#madsen-sv.c: madsen.c
#	ln -s madsen.c madsen-sv.c 
#madsen-sv.tst: madsen.s
#madsen-sv.tst: CFLAGS += -DSAINT_VENANT=1
#
#madsen.tst: madsen-sv.tst
#
#tohoku-gn.c: tohoku.c
#	ln -s tohoku.c tohoku-gn.c 
#tohoku-gn.tst: tohoku.s
#tohoku-gn.tst: CFLAGS += -DGN=1
#
#tohoku-hydro.c: tohoku.c
#	ln -s tohoku.c tohoku-hydro.c 
#tohoku-hydro.tst: tohoku.s
#tohoku-hydro.tst: CFLAGS += -DHYDRO=1
#
#shoal-ml.c: shoal.c
#	ln -s shoal.c shoal-ml.c 
#shoal-ml.tst: shoal.s
#shoal-ml.tst: CFLAGS += -DML=1

include $(BASILISK)/Makefile.defs
