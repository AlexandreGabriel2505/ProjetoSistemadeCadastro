CXX = g++
CXXFLAGS = -Wall -std=c++17
OBJS = main.o funcionario.o desenvolvedor.o gerente.o estagiario.o
TARGET = cadastro

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Funcionario.h Desenvolvedor.h Gerente.h Estagiario.h
	$(CXX) $(CXXFLAGS) -c main.cpp

funcionario.o: Funcionario.cpp Funcionario.h
	$(CXX) $(CXXFLAGS) -c Funcionario.cpp

desenvolvedor.o: Desenvolvedor.cpp Desenvolvedor.h Funcionario.h
	$(CXX) $(CXXFLAGS) -c Desenvolvedor.cpp

gerente.o: Gerente.cpp Gerente.h Funcionario.h
	$(CXX) $(CXXFLAGS) -c Gerente.cpp

estagiario.o: Estagiario.cpp Estagiario.h Funcionario.h
	$(CXX) $(CXXFLAGS) -c Estagiario.cpp

clean:
	rm -f *.o $(TARGET)
