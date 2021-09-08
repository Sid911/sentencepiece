#include "sentencepiece_processor_c.h"

void* sentencepiceInit() {
	return new sentencepiece::SentencePieceProcessor;
}

void sentencepieceDestroy(void* processorhandle) {
	auto processor = static_cast<sentencepiece::SentencePieceProcessor*> (processorhandle);
	delete processor;
}

void loadModelFile(void* processorhandle, char* filename) {
	auto processor =  static_cast<sentencepiece::SentencePieceProcessor*> (processorhandle);
	processor->LoadOrDie(filename);
}

int* encodeAsIds(void* processorhandle, char* input) {
	auto processor = static_cast<sentencepiece::SentencePieceProcessor*> (processorhandle);
	auto result = processor->EncodeAsIds(input);
	return result.data();
}