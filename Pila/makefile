INCLUDE = .

usocolas : usocolas.cpp cola.h cola.cpp pilamax_Cola.cpp
	g++  -o usocolas -I$(INCLUDE) usocolas.cpp pilamax_Cola.cpp
mrproper:
	rm usocolas

run: usocolas
	./usocolas
