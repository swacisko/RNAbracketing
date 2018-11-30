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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/BucketWorkflowDistributor.o \
	${OBJECTDIR}/GlobalParams.o \
	${OBJECTDIR}/Graph.o \
	${OBJECTDIR}/InputProcessor.o \
	${OBJECTDIR}/InputReader.o \
	${OBJECTDIR}/IterationController.o \
	${OBJECTDIR}/IterationGraph.o \
	${OBJECTDIR}/LongestPathCreator.o \
	${OBJECTDIR}/RandomBracketingGenerator.o \
	${OBJECTDIR}/ResultProcessor.o \
	${OBJECTDIR}/TopoSort.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f6 \
	${TESTDIR}/TestFiles/f3

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/bucketworkflowtest.o \
	${TESTDIR}/tests/inputprocessottest.o \
	${TESTDIR}/tests/iterationcontrollertest.o \
	${TESTDIR}/tests/longestpathcreatortest.o \
	${TESTDIR}/tests/randomgeneratortest.o \
	${TESTDIR}/tests/toposorttest.o

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rnabracketing

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rnabracketing: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rnabracketing ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/BucketWorkflowDistributor.o: BucketWorkflowDistributor.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BucketWorkflowDistributor.o BucketWorkflowDistributor.cpp

${OBJECTDIR}/GlobalParams.o: GlobalParams.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GlobalParams.o GlobalParams.cpp

${OBJECTDIR}/Graph.o: Graph.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graph.o Graph.cpp

${OBJECTDIR}/InputProcessor.o: InputProcessor.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InputProcessor.o InputProcessor.cpp

${OBJECTDIR}/InputReader.o: InputReader.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InputReader.o InputReader.cpp

${OBJECTDIR}/IterationController.o: IterationController.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IterationController.o IterationController.cpp

${OBJECTDIR}/IterationGraph.o: IterationGraph.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IterationGraph.o IterationGraph.cpp

${OBJECTDIR}/LongestPathCreator.o: LongestPathCreator.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LongestPathCreator.o LongestPathCreator.cpp

${OBJECTDIR}/RandomBracketingGenerator.o: RandomBracketingGenerator.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandomBracketingGenerator.o RandomBracketingGenerator.cpp

${OBJECTDIR}/ResultProcessor.o: ResultProcessor.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ResultProcessor.o ResultProcessor.cpp

${OBJECTDIR}/TopoSort.o: TopoSort.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TopoSort.o TopoSort.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/bucketworkflowtest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/inputprocessottest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/iterationcontrollertest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS}   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/longestpathcreatortest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS}   

${TESTDIR}/TestFiles/f6: ${TESTDIR}/tests/randomgeneratortest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS}   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/toposorttest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/bucketworkflowtest.o: tests/bucketworkflowtest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/bucketworkflowtest.o tests/bucketworkflowtest.cpp


${TESTDIR}/tests/inputprocessottest.o: tests/inputprocessottest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/inputprocessottest.o tests/inputprocessottest.cpp


${TESTDIR}/tests/iterationcontrollertest.o: tests/iterationcontrollertest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/iterationcontrollertest.o tests/iterationcontrollertest.cpp


${TESTDIR}/tests/longestpathcreatortest.o: tests/longestpathcreatortest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/longestpathcreatortest.o tests/longestpathcreatortest.cpp


${TESTDIR}/tests/randomgeneratortest.o: tests/randomgeneratortest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/randomgeneratortest.o tests/randomgeneratortest.cpp


${TESTDIR}/tests/toposorttest.o: tests/toposorttest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/toposorttest.o tests/toposorttest.cpp


${OBJECTDIR}/BucketWorkflowDistributor_nomain.o: ${OBJECTDIR}/BucketWorkflowDistributor.o BucketWorkflowDistributor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/BucketWorkflowDistributor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BucketWorkflowDistributor_nomain.o BucketWorkflowDistributor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/BucketWorkflowDistributor.o ${OBJECTDIR}/BucketWorkflowDistributor_nomain.o;\
	fi

${OBJECTDIR}/GlobalParams_nomain.o: ${OBJECTDIR}/GlobalParams.o GlobalParams.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/GlobalParams.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GlobalParams_nomain.o GlobalParams.cpp;\
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
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graph_nomain.o Graph.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Graph.o ${OBJECTDIR}/Graph_nomain.o;\
	fi

${OBJECTDIR}/InputProcessor_nomain.o: ${OBJECTDIR}/InputProcessor.o InputProcessor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/InputProcessor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InputProcessor_nomain.o InputProcessor.cpp;\
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
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InputReader_nomain.o InputReader.cpp;\
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
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IterationController_nomain.o IterationController.cpp;\
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
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IterationGraph_nomain.o IterationGraph.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/IterationGraph.o ${OBJECTDIR}/IterationGraph_nomain.o;\
	fi

${OBJECTDIR}/LongestPathCreator_nomain.o: ${OBJECTDIR}/LongestPathCreator.o LongestPathCreator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LongestPathCreator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LongestPathCreator_nomain.o LongestPathCreator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/LongestPathCreator.o ${OBJECTDIR}/LongestPathCreator_nomain.o;\
	fi

${OBJECTDIR}/RandomBracketingGenerator_nomain.o: ${OBJECTDIR}/RandomBracketingGenerator.o RandomBracketingGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RandomBracketingGenerator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandomBracketingGenerator_nomain.o RandomBracketingGenerator.cpp;\
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
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ResultProcessor_nomain.o ResultProcessor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ResultProcessor.o ${OBJECTDIR}/ResultProcessor_nomain.o;\
	fi

${OBJECTDIR}/TopoSort_nomain.o: ${OBJECTDIR}/TopoSort.o TopoSort.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TopoSort.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TopoSort_nomain.o TopoSort.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TopoSort.o ${OBJECTDIR}/TopoSort_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f6 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
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
