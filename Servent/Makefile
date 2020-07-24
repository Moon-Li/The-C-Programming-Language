LDFLAGS=-ljsoncpp -lcurl -lcrypto
INCLUDE=-Ispeech
Servant:servant.cc
	g++ -o $@ $^ $(INCLUDE) $(LDFLAGS) -std=c++11

.PHINY:clean
clean:
	rm -f servant
