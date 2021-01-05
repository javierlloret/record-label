#ifndef OggCompressor_hxx
#define OggCompressor_hxx

#include <string>
#include <fstream>

namespace OGG
{
	
	class WavNotFound
	{
	
	};
	



	inline void compress( const std::string& inWavFile, const std::string& outFilename, int bitrate)
	{
		std::ifstream wav;
		wav.open(inWavFile.c_str());
		if (!wav.is_open()) throw WavNotFound();

		std::ofstream oggFile(outFilename.c_str() );
	}
} // namesapce OGG

#endif
