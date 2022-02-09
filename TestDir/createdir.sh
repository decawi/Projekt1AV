#!/bin/sh

for a in 1 2 3 4 5 6 7 8; do 
	mkdir SubDir$a 
	cd SubDir$a	
	for b in 1 2 3 4 5; do 
		mkdir SubSubDir$a$b 
		cd SubSubDir$a$b	
		echo "Litta data" > fil1 
		echo "Litta mer data" > fil2 
		cd ..
	done 
	cd ..
done
