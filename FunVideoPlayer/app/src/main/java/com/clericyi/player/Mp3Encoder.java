package com.clericyi.player;

/**
 * author: ClericYi
 * time: 2020/3/10
 */
public class Mp3Encoder {
    public native int init(String pcmPath, int audioChannels, int bitRate, int sampleRate, String mp3Path);
    public native void encode();
    public native void destroy();
}
