//
//  RVS_Streamer_Media.h
//  RVS_Stream
//
//  Created by Lvyi on 4/21/15.
//  Copyright (c) 2015 ifziv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "Rvs_Streamer_Sys.h"

typedef enum enum_RVS_STREAMER_MEDIASTREAM_STATE{
    EN_RVS_STREAMER_MEDIASTREAM_STATE_CREATED        = 0,
    EN_RVS_STREAMER_MEDIASTREAM_STATE_CLOSED,
}EN_RVS_STREAMER_MEDIASTREAM_STATE;

typedef enum enum_RVS_STREAMER_VIDEO_TYPE
{
    E_RVS_STREAMER_VIDEO_TYPE_NOVIDEO            = 0,
    E_RVS_STREAMER_VIDEO_TYPE_JPEG               = 1,
    E_RVS_STREAMER_VIDEO_TYPE_H264               = 2,
}EN_RVS_STREAMER_VIDEO_TYPE;

typedef enum enum_RVS_STREAMER_AUDIO_TYPE
{
    E_RVS_STREAMER_AUDIO_TYPE_NOAUDIO           = 0,
    E_RVS_STREAMER_AUDIO_TYPE_AAC               = 1,
    E_RVS_STREAMER_AUDIO_TYPE_G711A             = 2,
    E_RVS_STREAMER_AUDIO_TYPE_G711U             = 3,
    E_RVS_STREAMER_AUDIO_TYPE_PCM16             = 4,//”√ªß¥´¥À∏Ò Ωµƒª∞£¨”…SDK«ø÷∆—πÀı≥…AAC∏Ò Ω¥´µ›∏¯CLIENT
}EN_RVS_STREAMER_AUDIO_TYPE;

typedef enum enum_RVS_STREAMER_PTZMOVE_MODE{
    EN_RVS_STREAMER_PTZMOVE_MODE_NOMODE        = 0,
    EN_RVS_STREAMER_PTZMOVE_MODE_PCTRL         = 0x01,
    EN_RVS_STREAMER_PTZMOVE_MODE_TCTRL         = 0x02,
    EN_RVS_STREAMER_PTZMOVE_MODE_ZCTRL         = 0x04,
    EN_RVS_STREAMER_PTZMOVE_MODE_XMOVE         = 0x08,
    EN_RVS_STREAMER_PTZMOVE_MODE_YMOVE         = 0x10,
    EN_RVS_STREAMER_PTZMOVE_MODE_ZMOVE         = 0x20
}EN_RVS_STREAMER_PTZMOVE_MODE;

typedef enum enum_RVS_STREAMER_STREAM_MODE{
    EN_RVS_STREAMER_STREAM_MODE_USESINGLE     = 0x00,
    EN_RVS_STREAMER_STREAM_MODE_USEMULTI      = 0x01
}EN_RVS_STREAMER_STREAM_MODE;


typedef struct {
    NSUInteger        PTZMoveMode;
    NSUInteger        torchMode;
    NSUInteger        rotateMode;
    NSUInteger        streamMode;
    NSUInteger        definition;
}ST_RVS_CAMERA_CAPACITY;

@interface RvsScheduleSetting : NSObject

@property (nonatomic, assign) NSUInteger  seq;
@property (nonatomic, assign) BOOL enable;
@property (nonatomic, assign) NSUInteger  startPoint;
@property (nonatomic, assign) NSUInteger  endPoint;

/**
    weekFlag 为二进制表示，低位表示周六，第七位为周日
    可用下面的枚举来&运算判断包含哪几天
    typedef NS_OPTIONS(NSUInteger, VDWeekFlag) {
         VDWeekFlagSunday = 1 << 6,
         VDWeekFlagMonday = 1 << 5,
         VDWeekFlagTuesday = 1 << 4,
         VDWeekFlagWednesday = 1 << 3,
         VDWeekFlagThursday = 1 << 2,
         VDWeekFlagFriday = 1 << 1,
         VDWeekFlagSaturday = 1
    };
 */
@property (nonatomic, assign) NSUInteger  weekFlag;

@end

@interface RvsTimeRecordSetting : NSObject

@property (nonatomic, retain) RvsScheduleSetting* schedule;
@property (nonatomic, assign) NSUInteger  param;

@end

@interface RvsMotionDetectSetting : NSObject

@property (nonatomic, retain) RvsScheduleSetting* schedule;
@property (nonatomic, assign) NSUInteger  sensitive;

@end


typedef struct
{
    NSUInteger          videoType;
    NSUInteger          width;
    NSUInteger          height;
    NSUInteger          bitRate;
    NSUInteger          frameRate;
    NSUInteger          iFrameInterval;
    NSUInteger          imageQuality;
   
    
}ST_RVS_STREAMER_CAMERASTREAM_INFO;

typedef struct
{
    NSUInteger              audioType;
    NSUInteger              sampleRate;
    NSUInteger              channel;
    NSUInteger              depth;
}ST_RVS_STREAMER_MIC_INFO;

typedef struct stRVS_STREAMER_MEDIA_AVDESC
{
    EN_RVS_STREAMER_VIDEO_TYPE         videoType;
    NSUInteger                         width;
    NSUInteger                         height;
    
    EN_RVS_STREAMER_AUDIO_TYPE          audioType;
    NSUInteger                          sampleRate;
    NSUInteger                          channel;
    NSUInteger                          depth;
}ST_RVS_STREAMER_MEDIA_AVDESC;

typedef enum enum_RVS_STREAMER_MEDIA_REVDATATYPE{
    E_RVS_STREAMER_MEDIA_REVDATATYPE_AUDIO = 1,
    E_RVS_STREAMER_MEDIA_REVDATATYPE_VIDEO = 2
}EN_RVS_STREAMER_MEDIA_REVDATATYPE;

typedef enum enum_RVS_STREAMER_MEDIA_COLLECT_FLAG{
    E_RVS_STREAMER_MEDIA_COLLECT_CLOSE                    = 0x00,
    E_RVS_STREAMER_MEDIA_COLLECT_OPEN                     = 0x01,
}EN_RVS_STREAMER_MEDIA_COLLECT_FLAG;

typedef enum enum_RVS_STREAMER_JPEG_TYPE
{
    EN_RVS_STREAMER_JPEG_TYPE_HD           = 0,
    EN_RVS_STREAMER_JPEG_TYPE_NORMAL       = 1,
    EN_RVS_STREAMER_JPEG_TYPE_ICON         = 2,
}EN_RVS_STREAMER_JPEG_TYPE;


typedef enum enum_RVS_STREAMER_DEFINITION{
    
    EN_RVS_STREAMER_DEFINITION_NONE = 0,
    EN_RVS_STREAMER_DEFINITION_SD_640_480 = 0x01,          //标清
    EN_RVS_STREAMER_DEFINITION_SD_800_600 = 0x02,          //标清
    EN_RVS_STREAMER_DEFINITION_HD_1280_720 = 0x04,          //高清
    
}EN_RVS_STREAMER_DEFINITION;


typedef enum enum_RVS_STREAMER_WATER_POSION
{
    EN_RVS_STREAMER_WATER_POSION_LT = 0, //左上
    EN_RVS_STREAMER_WATER_POSION_RT, //右上
    EN_RVS_STREAMER_WATER_POSION_LB,//左下
    EN_RVS_STREAMER_WATER_POSION_RB, //右下
    EN_RVS_STREAMER_WATER_POSION_TM, // 上中
    EN_RVS_STREAMER_WATER_POSION_BM, // 下中
    EN_RVS_STREAMER_WATER_POSION_NOUSED //不用
    
}EN_RVS_STREAMER_WATER_POSION;

@protocol Rvs_Streamer_Media_AV_Delegate <NSObject>

- (void)onMediaChannelState:(unsigned long long)peerCid
           MediaStreamState:(EN_RVS_STREAMER_MEDIASTREAM_STATE)state
               ChannelCount:(NSUInteger)channelCount;

//需要一个IDR帧
- (void)onKeyFrameRequiredForCamera:(NSUInteger) cameraId
                             Stream:(NSUInteger) streamId;


- (void)onGetJpegFrame:(unsigned char**)ppFrameBuf
           FrameLength:(NSUInteger*) pFrameBufLength
              JpegType:(EN_RVS_STREAMER_JPEG_TYPE)jpegType
             ForCamera:(NSUInteger) cameraId
                Stream:(NSUInteger) streamId;


- (void)onAdjustVideoBitrate:(NSUInteger)bitRate
                   Framerate:(NSUInteger)frameRate
                ImageQuality:(NSUInteger)imageQuality
              IFrameInterval:(NSUInteger)iFrameInterval
                   ForCamera:(NSUInteger) cameraId
                      Stream:(NSUInteger) streamId;


- (void)onVideoCollectFlagNotify:(EN_RVS_STREAMER_MEDIA_COLLECT_FLAG)flag
                       ForCamera:(NSUInteger) cameraId
                          Stream:(NSUInteger) streamId;

- (void)onAudioCollectFlagNotify:(EN_RVS_STREAMER_MEDIA_COLLECT_FLAG)flag
                          ForMic:(NSUInteger)micId;


- (void)onRawVideoCollectFlagNotify:(EN_RVS_STREAMER_MEDIA_COLLECT_FLAG)flag
                       ForCamera:(NSUInteger) cameraId
                          Stream:(NSUInteger) streamId;


@end

@protocol Rvs_Streamer_Media_RevStream_Delegate <NSObject>

- (void)onRevStreamDataToPlay:(unsigned char*)pRevData
                   DataLength:(NSUInteger) length
                     DataType:(EN_RVS_STREAMER_MEDIA_REVDATATYPE) dataType
                  FromPeerCID:(unsigned long long)peerCID;

- (NSInteger)onRevStreamStatus:(unsigned long long)peerCid
                           Url:(NSString*)url
                        Status:(NSUInteger)status;


@end

@protocol Rvs_Streamer_Media_Record_Delegate <NSObject>

/**
 定时录制开启
 */
- (void)onRecordStart;


/**
 定时录制关闭
 */
- (void)onRecordStop;



/**
 定时录制任务更新

 @param recordSettings 为RvsTimeRecordSetting类型
 @param cameraId 摄像头ID,一般为0
 */
- (void)onScheduledRecordSettingUpdate:(NSArray*)recordSettings ForCameraID:(NSUInteger)cameraId;


@end


@protocol Rvs_Streamer_Media_MotionDetect_Delegate <NSObject>


/**
 运动侦测录制启动
 */
- (void)onMotionDetectStart;


/**
 运动侦测录制结束
 */
- (void)onMotionDetectStop;


/**
 运动侦测任务更新

 @param motionSettings 为RvsMotionDetectSetting类型
 @param cameraId 摄像头id,一般为0
 */
- (void)onMotionDetectSettingUpdate:(NSArray*)motionSettings ForCameraID:(NSUInteger)cameraId;

/**
 侦测报警发出
 
 @param cameraId 镜头ID，一般为0
 */
- (void)onMotionDetectAlarmOut:(NSUInteger)cameraId;

@end


@protocol Rvs_Streamer_Media_H264Encoder_Delegate <NSObject>

- (RVS_HANDLE)onVideoEncoderCreateWithWidth:(NSUInteger)width
                                     Height:(NSUInteger)height;

- (NSInteger)onVideoEncodeFrameWithHandle:(RVS_HANDLE)handle
                          NeedIFrame:(BOOL*)needIFrame
                         YUV420Frame:(unsigned char*)yuv420Frame
                           TimeStamp:(NSUInteger)timeStamp
                           H264Frame:(unsigned char**)h264Frame
                        H264FrameLen:(NSUInteger*)h264FrameLen;


- (NSInteger)onVideoEncoderCloseWithHandle:(RVS_HANDLE)handle;


@end


@interface Rvs_Streamer_Media : NSObject



/**
 *各种代理回调设置
 */


@property (nonatomic, assign) id<Rvs_Streamer_Media_AV_Delegate> mediaDelegate;
@property (nonatomic, assign) id<Rvs_Streamer_Media_RevStream_Delegate> revStreamDelegate;
@property (nonatomic, assign) id<Rvs_Streamer_Media_H264Encoder_Delegate> h264EncoderDelegate;


/**
 如果你使用了RvsStreamerInitHelper初始化SDK，请使用RvsObserverCenter 添加响应代理 addObsever
 */
@property (nonatomic, assign) id<Rvs_Streamer_Media_Record_Delegate> recordDelegate;
@property (nonatomic, assign) id<Rvs_Streamer_Media_MotionDetect_Delegate> motionDetectDelegate;



//设置总共镜头数目
- (NSInteger)setCameraCount:(NSUInteger) cameraCount;

//设置每个镜头的视频流通道数
- (NSInteger)setStreamCount:(NSUInteger) streamCount
			 ForCamera:(NSUInteger) cameraId;

//设置每个视频流通道到的视频流参数
- (NSInteger)setCameraStreamProperty:(const ST_RVS_STREAMER_CAMERASTREAM_INFO*) videoFormat
			ForCamera:(NSUInteger) cameraId
			   Stream:(NSUInteger) streamId;

- (NSInteger)changeCameraStreamProperty:(const ST_RVS_STREAMER_CAMERASTREAM_INFO*) videoFormat
                           ForCamera:(NSUInteger) cameraId
                              Stream:(NSUInteger) streamId;


- (NSInteger)setCameraCapacity:(const ST_RVS_CAMERA_CAPACITY*)cameraCapacity
                     ForCamera:(NSUInteger) cameraId;

/**
 *  设置视频录制路径
 *
 *  @param recordPath 路径
 *
 *  @return 设置结果
 */
- (NSInteger)setRecordPath:(NSString *)recordPath;


//设置麦克风数，也就是音频流通道数
- (NSInteger)setMicCount:(NSUInteger) micCount;

//设置每个音频流通道到的音频流参数
- (NSInteger)setAudioProperty:(const ST_RVS_STREAMER_MIC_INFO*) audioFormat
			   ForMic:(NSUInteger)micId;


//发送视频流
- (NSInteger)writeVideoData:(unsigned char*) videoData
            DataLength:(NSUInteger) dataLength
             TimeStamp:(NSUInteger) timeStamp
              IsIFrame:(BOOL)isIFrame
			ForCamera:(NSUInteger) cameraId
			   Stream:(NSUInteger) streamId;

- (NSInteger)writeRawVideoData:(unsigned char*) videoData
                    DataLength:(NSUInteger) dataLength
                     TimeStamp:(NSUInteger) timeStamp
                     ForCamera:(NSUInteger) cameraId
                        Stream:(NSUInteger) streamId;

//发送音频流
- (NSInteger)writeAudioData:(unsigned char*)audioData
            DataLength:(NSUInteger) dataLength
             TimeStamp:(NSUInteger) timeStamp
			   ForMic:(NSUInteger)micId;


- (NSInteger)getRevProperty:(ST_RVS_STREAMER_MEDIA_AVDESC*) pMediaDesc FromPeerCID:(unsigned long long)peerCid;


- (NSInteger)setScheduleRecordSettings:(NSArray*)scheduleRecordSettings ForCamera:(NSUInteger)cameraId;

- (NSArray*)getScheduleRecordSettingsForCamera:(NSUInteger)cameraId;

- (NSInteger)setMotionDetectSettings:(NSArray*)motionDetectSettings ForCamera:(NSUInteger)cameraId;

- (NSArray*)getMotionDetectSettingsForCamera:(NSUInteger)cameraId;


//发送视频流
- (NSInteger)asynWriteVideoData:(unsigned char*) videoData
                     DataLength:(NSUInteger) dataLength
                      TimeStamp:(NSUInteger) timeStamp
                       IsIFrame:(BOOL)isIFrame
                      ForHandle:(RVS_HANDLE)handle;


- (void)setVideoEncoderForAliveFlag:(BOOL)closeEncAliveFlag;


- (void)brightnessAdjustWithYUVData:(unsigned char*)data Width:(NSUInteger)width Height:(NSUInteger)height;

- (void)setWaterMarkPosition:(int)position;

- (void)addWaterMark:(unsigned char*)yuvBuf Width:(int)width Height:(int)height;

- (void)startCustomRecordForCamera:(NSUInteger)cameraId Stream:(NSUInteger)streamId;

- (void)stopCustomRecordForCamera:(NSUInteger)cameraId Stream:(NSUInteger)streamId;


@end
