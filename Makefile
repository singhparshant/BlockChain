all:
	g++ -lstdc++  -std=c++11  -stdlib=libc++  -x c++  main.cpp Block.cpp Blockchain.cpp sha256.cpp -o Blockchain