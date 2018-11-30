#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/DisjointComponentMerger.o \
	${OBJECTDIR}/GlobalIterator.o \
	${OBJECTDIR}/GlobalParams.o \
	${OBJECTDIR}/Graph.o \
	${OBJECTDIR}/GraphConnectedComponents.o \
	${OBJECTDIR}/InputProcessor.o \
	${OBJECTDIR}/InputReader.o \
	${OBJECTDIR}/IterationController.o \
	${OBJECTDIR}/IterationGraph.o \
	${OBJECTDIR}/MIS.o \
	${OBJECTDIR}/MISNodes.o \
	${OBJECTDIR}/Makros.o \
	${OBJECTDIR}/RandomBracketingGenerator.o \
	${OBJECTDIR}/ResultProcessor.o \
	${OBJECTDIR}/ResultTester.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/mistest.o \
	${TESTDIR}/tests/newsimpletest.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rnabracketingmis

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rnabracketingmis: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rnabracketingmis ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/DisjointComponentMerger.o: DisjointComponentMerger.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DisjointComponentMerger.o DisjointComponentMerger.cpp

${OBJECTDIR}/GlobalIterator.o: GlobalIterator.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GlobalIterator.o GlobalIterator.cpp

${OBJECTDIR}/GlobalParams.o: GlobalParams.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GlobalParams.o GlobalParams.cpp

${OBJECTDIR}/Graph.o: Graph.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graph.o Graph.cpp

${OBJECTDIR}/GraphConnectedComponents.o: GraphConnectedComponents.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GraphConnectedComponents.o GraphConnectedComponents.cpp

${OBJECTDIR}/InputProcessor.o: InputProcessor.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InputProcessor.o InputProcessor.cpp

${OBJECTDIR}/InputReader.o: InputReader.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InputReader.o InputReader.cpp

${OBJECTDIR}/IterationController.o: IterationController.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IterationController.o IterationController.cpp

${OBJECTDIR}/IterationGraph.o: IterationGraph.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IterationGraph.o IterationGraph.cpp

${OBJECTDIR}/MIS.o: MIS.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MIS.o MIS.cpp

${OBJECTDIR}/MISNodes.o: MISNodes.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MISNodes.o MISNodes.cpp

${OBJECTDIR}/Makros.o: Makros.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Makros.o Makros.cpp

${OBJECTDIR}/RandomBracketingGenerator.o: RandomBracketingGenerator.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandomBracketingGenerator.o RandomBracketingGenerator.cpp

${OBJECTDIR}/ResultProcessor.o: ResultProcessor.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ResultProcessor.o ResultProcessor.cpp

${OBJECTDIR}/ResultTester.o: ResultTester.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ResultTester.o ResultTester.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/mistest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/newsimpletest.o: tests/newsimpletest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newsimpletest.o tests/newsimpletest.cpp


${TESTDIR}/tests/mistest.o: tests/mistest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/mistest.o tests/mistest.cpp


${OBJECTDIR}/DisjointComponentMerger_nomain.o: ${OBJECTDIR}/DisjointComponentMerger.o DisjointComponentMerger.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DisjointComponentMerger.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DisjointComponentMerger_nomain.o DisjointComponentMerger.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DisjointComponentMerger.o ${OBJECTDIR}/DisjointComponentMerger_nomain.o;\
	fi

${OBJECTDIR}/GlobalIterator_nomain.o: ${OBJECTDIR}/GlobalIterator.o GlobalIterator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/GlobalIterator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GlobalIterator_nomain.o GlobalIterator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/GlobalIterator.o ${OBJECTDIR}/GlobalIterator_nomain.o;\
	fi

${OBJECTDIR}/GlobalParams_nomain.o: ${OBJECTDIR}/GlobalParams.o GlobalParams.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/GlobalParams.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GlobalParams_nomain.o GlobalParams.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/GlobalParams.o ${OBJECTDIR}/GlobalParams_nomain.o;\
	fi

${OBJECTDIR}/Graph_nomain.o: ${OBJECTDIR}/Graph.o Graph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Graph.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graph_nomain.o Graph.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Graph.o ${OBJECTDIR}/Graph_nomain.o;\
	fi

${OBJECTDIR}/GraphConnectedComponents_nomain.o: ${OBJECTDIR}/GraphConnectedComponents.o GraphConnectedComponents.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/GraphConnectedComponents.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GraphConnectedComponents_nomain.o GraphConnectedComponents.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/GraphConnectedComponents.o ${OBJECTDIR}/GraphConnectedComponents_nomain.o;\
	fi

${OBJECTDIR}/InputProcessor_nomain.o: ${OBJECTDIR}/InputProcessor.o InputProcessor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/InputProcessor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InputProcessor_nomain.o InputProcessor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/InputProcessor.o ${OBJECTDIR}/InputProcessor_nomain.o;\
	fi

${OBJECTDIR}/InputReader_nomain.o: ${OBJECTDIR}/InputReader.o InputReader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/InputReader.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InputReader_nomain.o InputReader.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/InputReader.o ${OBJECTDIR}/InputReader_nomain.o;\
	fi

${OBJECTDIR}/IterationController_nomain.o: ${OBJECTDIR}/IterationController.o IterationController.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IterationController.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IterationController_nomain.o IterationController.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/IterationController.o ${OBJECTDIR}/IterationController_nomain.o;\
	fi

${OBJECTDIR}/IterationGraph_nomain.o: ${OBJECTDIR}/IterationGraph.o IterationGraph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IterationGraph.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IterationGraph_nomain.o IterationGraph.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/IterationGraph.o ${OBJECTDIR}/IterationGraph_nomain.o;\
	fi

${OBJECTDIR}/MIS_nomain.o: ${OBJECTDIR}/MIS.o MIS.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MIS.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MIS_nomain.o MIS.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MIS.o ${OBJECTDIR}/MIS_nomain.o;\
	fi

${OBJECTDIR}/MISNodes_nomain.o: ${OBJECTDIR}/MISNodes.o MISNodes.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MISNodes.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MISNodes_nomain.o MISNodes.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MISNodes.o ${OBJECTDIR}/MISNodes_nomain.o;\
	fi

${OBJECTDIR}/Makros_nomain.o: ${OBJECTDIR}/Makros.o Makros.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Makros.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Makros_nomain.o Makros.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Makros.o ${OBJECTDIR}/Makros_nomain.o;\
	fi

${OBJECTDIR}/RandomBracketingGenerator_nomain.o: ${OBJECTDIR}/RandomBracketingGenerator.o RandomBracketingGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RandomBracketingGenerator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandomBracketingGenerator_nomain.o RandomBracketingGenerator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RandomBracketingGenerator.o ${OBJECTDIR}/RandomBracketingGenerator_nomain.o;\
	fi

${OBJECTDIR}/ResultProcessor_nomain.o: ${OBJECTDIR}/ResultProcessor.o ResultProcessor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ResultProcessor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ResultProcessor_nomain.o ResultProcessor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ResultProcessor.o ${OBJECTDIR}/ResultProcessor_nomain.o;\
	fi

${OBJECTDIR}/ResultTester_nomain.o: ${OBJECTDIR}/ResultTester.o ResultTester.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ResultTester.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ResultTester_nomain.o ResultTester.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ResultTester.o ${OBJECTDIR}/ResultTester_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
