#include "sentencepiece_processor_c.h"



void* sentencepiceInit() {
	return new sentencepiece::SentencePieceProcessor;
}

void sentencepieceDestroy(void* processorhandle) {
	auto processor = static_cast<sentencepiece::SentencePieceProcessor*> (processorhandle);
	delete processor;
}

void free_int_array(int* arr) {
	free(arr);
}

void loadModelFile(void* processorhandle, char* filename) {
	auto processor =  static_cast<sentencepiece::SentencePieceProcessor*> (processorhandle);
	processor->LoadOrDie(filename);
}

int* encodeAsIds(void* processorhandle, char* input) {
	auto processor = static_cast<sentencepiece::SentencePieceProcessor*> (processorhandle);
	auto result = processor->EncodeAsIds(input);
	return result.get_allocator().allocate(result.size());
}

string_array encodeAsPieces(void* processorhandle, char* input) {
	auto processor = static_cast<sentencepiece::SentencePieceProcessor*> (processorhandle);
	auto result =  processor->EncodeAsPieces(input);
	std::vector<char*> cstrings{};
	for (auto& i : result)
		cstrings.push_back(&i.front());

	return createStringArray(cstrings.data(), cstrings.size());
}