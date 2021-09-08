#include "sentencepiece_processor.h"
#include <stdint.h>
#include <vector>

extern "C"{
void* sentencepiceInit();
void sentencepieceDestroy(void* processorhandle);
void loadModelFile(void* processorhandle, char* filename);
int* encodeAsIds(void* processorhandle, char* input);
}