cuerda.gif: datos.txt animacion.py
	python animacion.py

datos.txt: cuerda.x
	./cuerda.x >> datos.txt

cuerda.x: cuerda.cpp
	c++ cuerda.cpp -o cuerda.x
