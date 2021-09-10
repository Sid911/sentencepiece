#include "sentencepiece_processor.h"
#include <stdint.h>
#include <vector>
struct string_array
{
	char** data;
	unsigned int size;
};

string_array createStringArray(char** cstring, unsigned int size) {
	string_array s;
	s.data = cstring;
	s.size = size;
	return s;
}

extern "C"{
void* sentencepiceInit();
void sentencepieceDestroy(void* processorhandle);
void loadModelFile(void* processorhandle, char* filename);

int* encodeAsIds(void* processorhandle, char* input);
string_array encodeAsPieces(void* processorhandle, char* input);

}