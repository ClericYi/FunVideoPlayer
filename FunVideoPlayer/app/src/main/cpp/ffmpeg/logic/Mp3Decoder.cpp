#include "../core/accompany_decoder_controller.h"
#include "com_clericyi_player_Mp3Decoder.h"
#define LOG_TAG "Mp3Decoder"

AccompanyDecoderController* decoderController;

extern "C" JNIEXPORT jint JNICALL Java_com_clericyi_player_Mp3Decoder_init
  (JNIEnv * env, jobject obj, jstring mp3PathParam, jstring pcmPathParam) {
	const char* pcmPath = env->GetStringUTFChars(pcmPathParam, NULL);
	const char* mp3Path = env->GetStringUTFChars(mp3PathParam, NULL);
	decoderController = new AccompanyDecoderController();
	decoderController->init(mp3Path, pcmPath);
	env->ReleaseStringUTFChars(mp3PathParam, mp3Path);
	env->ReleaseStringUTFChars(pcmPathParam, pcmPath);
	return 1;
}

extern "C" JNIEXPORT void JNICALL Java_com_clericyi_player_Mp3Decoder_decode
  (JNIEnv * env, jobject obj) {
	LOGI("enter Java_com_phuket_tour_decoder_Mp3Decoder_decode...");
	if(decoderController) {
		decoderController->decode();
	}
	LOGI("leave Java_com_phuket_tour_decoder_Mp3Decoder_decode...");
}

extern "C" JNIEXPORT void JNICALL Java_com_clericyi_player_Mp3Decoder_destroy
  (JNIEnv * env, jobject obj) {
	if(decoderController) {
		decoderController->destroy();
		delete decoderController;
		decoderController = NULL;
	}
}
