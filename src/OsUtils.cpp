////////////////////////////////////////////////////////////////
//                                                            //
//      OsUtils.cpp                                           //
//      HaselLoyance 2017, Unlicensed                         //
//      https://github.com/HaselLoyance/osu-parser            //
//                                                            //
////////////////////////////////////////////////////////////////

#include "OsUtils.h"

using namespace osuParser;
using namespace std;

// Checks if input is active in an input mask
//   inputs, InputMask, inputs mask
//   input, InputType, input to check if is active
// Returns true if input is active in an input mask, false otherwise
bool osuParser::IsInputActive(const InputMask & inputs, const InputType & input)
{
	return IsBitSet(inputs, input);
}

// Checks if mod is active in a mod mask
//   mods, ModMask, mods mask
//   mod, ModType, mod to check if is active
// Returns true if mod is active in a mod mask, false otherwise
bool osuParser::IsModActive(const ModMask & mods, const ModType & mod)
{
	return IsBitSet(mods, mod);
}

// Decompress LZMA-compressed buffer
//   inBuf, vector<uint8_t>, input buffer with LZMA-compressed bytes
//   outBuf, &vector<uint8_t>, output buffer where decompressed data will be written
void osuParser::DecompressLZMA(const vector<uint8_t> &inBuf, vector<uint8_t> & outBuf)
{
	outBuf.clear();
	outBuf.resize(inBuf.size() * 4);
	size_t dstLen = outBuf.size();
	size_t srcLen = inBuf.size() - LZMA_PROPS_SIZE - 8;
	LzmaUncompress(&outBuf[0], &dstLen, &inBuf[LZMA_PROPS_SIZE + 8], &srcLen, &inBuf[0], LZMA_PROPS_SIZE);
	outBuf.resize(dstLen);
}