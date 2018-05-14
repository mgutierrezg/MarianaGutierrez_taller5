placas.pdf: grafica.py datos.txt
	python grafica.py
datos.txt: placas
	./placas > datos.txt
placas:
	c++ placas.cpp -o placas
