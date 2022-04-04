#All Relevant Files
Files = IO.o Main.o Memory_Allocation.o Simulation.o Thomas.o VarDeclare.o 

#Compiler Choice
Compiler = g++

#Compile Flags
Flags = -lm -O3

#Final Binary
Exec: $(Files)
	@echo "Linking all Object Files"
	@$(Compiler) $(Flags) $(Files) -o Exec

#sub.o: sub.cpp
#	@echo "Building sub..."
#	@$(Compiler) $(Flags) -o sub.o -c sub.cpp

clean:
	@echo "Removing Build Relics..."
	@rm *.o
