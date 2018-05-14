caos.pdf: datos.txt caos.py
	python caos.py

datos.txt: caos.x
	./caos.x >> datos.txt

caos.x: caos.cpp
	c++ caos.cpp -o caos.x
