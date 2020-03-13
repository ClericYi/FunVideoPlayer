cmake_minimum_required(VERSION 3.4.1)

# 定义变量
set(ffmpeg_lib_dir ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})
set(ffmpeg_head_dir ${CMAKE_SOURCE_DIR}/ffmpeg)

add_library( # Sets the name of the library.
        audioencoder
        SHARED
        # lame
        lame/bitstream.c lame/encoder.c lame/gain_analysis.c
        lame/lame.c lame/id3tag.c lame/mpglib_interface.c
        lame/newmdct.c lame/presets.c lame/psymodel.c
        lame/quantize.c lame/fft.c lame/quantize_pvt.c
        lame/reservoir.c lame/set_get.c lame/tables.c
        lame/takehiro.c lame/util.c lame/vbrquantize.c
        lame/VbrTag.c lame/version.c
        # mine
        audioencoder/audioencoder.cpp
        audioencoder/mp3_encoder.cpp
        # ffpmeg
        ffmpeg/logic/native-lib.cpp
        ffmpeg/core/accompany_decoder_controller.cpp
        ffmpeg/core/accompany_decoder.cpp
        ffmpeg/logic/Mp3Decoder.cpp
        )

# 3. 添加ffmpeg相关的so库
add_library( avutil
        SHARED
        IMPORTED )
set_target_properties( avutil
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavutil.so )

add_library( swresample
        SHARED
        IMPORTED )
set_target_properties( swresample
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libswresample.so )

add_library( avcodec
        SHARED
        IMPORTED )
set_target_properties( avcodec
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavcodec.so )

add_library( avfilter
        SHARED
        IMPORTED)
set_target_properties( avfilter
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavfilter.so )

add_library( swscale
        SHARED
        IMPORTED)
set_target_properties( swscale
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libswscale.so )

add_library( avformat
        SHARED
        IMPORTED)
set_target_properties( avformat
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavformat.so )

add_library( avdevice
        SHARED
        IMPORTED)
set_target_properties( avdevice
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavdevice.so )


find_library( # Sets the name of the path variable.
        log-lib
        log)

# 引入头文件
include_directories(${ffmpeg_head_dir}/include)

target_link_libraries( # Specifies the target library.
        audioencoder
        # ffmpeg
        avutil
        swresample
        avcodec
        avfilter
        swscale
        avformat
        avdevice

        ${log-lib})