//
// Created by Cleric Yi on 2020/3/10.
//


#ifndef PHUKET_TOUR_MP3_ENCODER
#define PHUKET_TOUR_MP3_ENCODER

#include "lame/lame.h"

class Mp3Encoder {
private:
    FILE* pcmFile;
    FILE* mp3File;
    lame_t lameClient;

public:
    Mp3Encoder();
    ~Mp3Encoder();

    int init(const char* pcmFilePath, const char *mp3FilePath, int sampleRate, int channels, int bitRate);
    void Encode();
    void Destroy();
};

#endif //PHUKET_TOUR_MP3_ENCODER