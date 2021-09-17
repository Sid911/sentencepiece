#include "sentencepiece_processor_c.h"
void* sentencepieceInit() {
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

int checkModelLoaded(void* processorhandle) { 
	auto processor = static_cast<sentencepiece::SentencePieceProcessor*> (processorhandle);
	if (processor->status().code() == sentencepiece::util::StatusCode::kOk) {
		return 1;
	}
	return 0;
};

void resetVocabulary(void* processorhandle) {
	auto processor = static_cast<sentencepiece::SentencePieceProcessor*> (processorhandle);
	processor->ResetVocabulary();
}

struct Int32Array encodeAsIds(void* processorhandle, char* input) {
	auto processor = static_cast<sentencepiece::SentencePieceProcessor*> (processorhandle);
	auto result = processor->EncodeAsIds(input);
	auto c_result = createInt32Array(result.data(), result.size());
	return c_result;
}

struct StringArray encodeAsPieces(void* processorhandle, char* input) {
	auto processor = static_cast<sentencepiece::SentencePieceProcessor*> (processorhandle);
	auto result =  processor->EncodeAsPieces(input);
	std::vector<char*> cstrings{};
	for (auto& i : result)
		cstrings.push_back(&i.front());

	return createStringArray(cstrings.data(), cstrings.size());
}

//struct string_array decodeFromIds(void* processorhandle,int* ids) {
//	//Todo: Remember to implement
//}
