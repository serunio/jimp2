all:
	gcc src/grafD.c 	-o exe/grafD.out
	gcc src/Dijkstra.c 	-o exe/Dijkstra.out
	gcc src/Astar.c 	-o exe/Astar.out
	gcc src/grafBF.c 	-o exe/grafBF.out
	gcc src/BellmanFord.c 	-o exe/BellmanFord.out
	./exe/grafBF.out
	./exe/grafD.out
	./exe/Labirynt -numery > grafy/labirynt.txt
