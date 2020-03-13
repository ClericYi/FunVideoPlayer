package com.clericyi.player;

public class Mp3Decoder {

	public native int init(String mp3FilePath, String pcmFilePath);
	
	public native void decode();
	
	public native void destroy();

}

