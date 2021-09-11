#include "sentencepiece_processor.h"
#include <stdint.h>
#include <vector>
struct string_array
{
	char** data;
	int size;
};
struct Int32Array 
{
	int* data;
	int len;
};

string_array createStringArray(char** cstring, int size) {
	string_array s;
	s.data = cstring;
	s.size = size;
	return s;
}

Int32Array createInt32Array(int* arr, int len) {
	Int32Array a;
	a.data = arr;
	a.len = len;
	return a;
}

extern "C"{
void* sentencepiceInit();
void sentencepieceDestroy(void* processorhandle);
void loadModelFile(void* processorhandle, char* filename);
bool checkModelLoaded(void* processorhandle);
void resetVocabulary(void* processorhandle);
struct Int32Array encodeAsIds(void* processorhandle, char* input);
struct string_array encodeAsPieces(void* processorhandle, char* input);

}