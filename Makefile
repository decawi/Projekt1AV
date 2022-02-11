run: out
	./out

out:
	g++ main.cpp Antivirus.cpp -o out

clean:
	rm out
