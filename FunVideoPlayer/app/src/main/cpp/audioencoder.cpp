//
// Created by Cleric Yi on 2020/3/10.
//

#include "com_clericyi_player_Mp3Encoder.h"
#include "common/CommonTools.h"
#include "mp3_encoder.h"
#include <jni.h>
#include <string>

#define LOG_TAG "Mp3Encoder"

Mp3Encoder *encoder = NULL;

extern "C" JNIEXPORT jint JNICALL Java_com_clericyi_player_Mp3Encoder_init
        (JNIEnv *env, jobject obj, jstring pcmPathParam, jint channels, jint bitRate,
         jint sampleRate, jstring mp3PathParam) {
    const char *pcmPath = env->GetStringUTFChars(pcmPathParam, NULL);
    const char *mp3Path = env->GetStringUTFChars(mp3PathParam, NULL);
    LOGI("mp3Path is %s...", mp3Path);
    encoder = new Mp3Encoder();
    int ret = encoder->init(pcmPath, mp3Path, sampleRate, channels, bitRate);
    env->ReleaseStringUTFChars(mp3PathParam, mp3Path);
    env->ReleaseStringUTFChars(pcmPathParam, pcmPath);
    return ret;
}

extern "C" JNIEXPORT void JNICALL Java_com_clericyi_player_Mp3Encoder_encode
        (JNIEnv *, jobject) {
    if (NULL != encoder) {
        encoder->Encode();
    }
}

extern "C" JNIEXPORT void JNICALL Java_com_clericyi_player_Mp3Encoder_destroy
        (JNIEnv *, jobject) {
    if (NULL != encoder) {
        encoder->Destroy();
        delete encoder;
        encoder = NULL;
    }
}
