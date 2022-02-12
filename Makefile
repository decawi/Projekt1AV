run: out
	./out

out:
	g++ main.cpp Antivirus.cpp -std=c++17 -lstdc++fs -o out

clean:
	rm out
