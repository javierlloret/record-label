#ifndef FraunhofferTools_hxx
#define FraunhofferTools_hxx

#include <fstream>

enum frk_Rate{ bps96, bps128, bps192, bps240 };


inline int frk_MP3_compression(const char* inWavFile, const char* outFile, frk_Rate rate)
{
	std::ifstream wav;
	wav.open(inWavFile);
	if (!wav.is_open()) return -1;

	std::ofstream mp3(outFile);
	return 0;
}

#endif

