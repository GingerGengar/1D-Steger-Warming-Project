#All Relevant Files
Files = Bound_Cond.o Flux.o IO.o Initial_Profile.o Mappings.o Memory_Allocate.o Steger_Warming.o Vars.o Main.o 

#Compiler Choice
Compiler = g++

#Compile Flags
Flags = -lm -O3 -flto

#Final Binary
Exec: $(Files)
	@echo "Linking all Object Files"
	@$(Compiler) $(Flags) $(Files) -o Exec

Bound_Cond.o: Bound_Cond.cpp
	@echo "Building Bound_Cond..."
	@$(Compiler) $(Flags) -o Bound_Cond.o -c Bound_Cond.cpp

Flux.o: Flux.cpp
	@echo "Building Flux..."
	@$(Compiler) $(Flags) -o Flux.o -c Flux.cpp

IO.o: IO.cpp
	@echo "Building IO..."
	@$(Compiler) $(Flags) -o IO.o -c IO.cpp

Initial_Profile.o: Initial_Profile.cpp
	@echo "Building Initial_Profile..."
	@$(Compiler) $(Flags) -o Initial_Profile.o -c Initial_Profile.cpp

Mappings.o: Mappings.cpp
	@echo "Building Mappings..."
	@$(Compiler) $(Flags) -o Mappings.o -c Mappings.cpp

Memory_Allocate.o: Memory_Allocate.cpp
	@echo "Building Memory_Allocate..."
	@$(Compiler) $(Flags) -o Memory_Allocate.o -c Memory_Allocate.cpp

Steger_Warming.o: Steger_Warming.cpp
	@echo "Building Steger_Warming..."
	@$(Compiler) $(Flags) -o Steger_Warming.o -c Steger_Warming.cpp

Vars.o: Vars.cpp
	@echo "Building Vars..."
	@$(Compiler) $(Flags) -o Vars.o -c Vars.cpp

Main.o: Main.cpp
	@echo "Building Main..."
	@$(Compiler) $(Flags) -o Main.o -c Main.cpp

#sub.o: sub.cpp
#	@echo "Building sub..."
#	@$(Compiler) $(Flags) -o sub.o -c sub.cpp

clean:
	@echo "Removing Build Relics..."
	@rm *.o
