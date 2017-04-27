//
//  RvsStreamerInitHelper.h
//  Rvs_Streamer
//
//  Created by GYJ on 16/6/13.
//  Copyright © 2016年 ifziv. All rights reserved.
//

/**
 * 初始化AVS SDK使用，并接收登陆信息等。
 * 生命周期 初始化 --- login --- logout;
 * @author KindDeath
 */

#import <Foundation/Foundation.h>
#import "Rvs_Streamer.h"

/// 系统访问权限
typedef enum : NSUInteger {
    RvsStreamerPrivacyCamera,
    RvsStreamerPrivacyMicrophone,
    RvsStreamerPrivacyPhotoAlbum,
} RvsStreamerPrivacy;


@protocol RvsStreamerInitHelperDelegate;

@interface RvsStreamerInitHelper : NSObject

@property (nonatomic, assign) NSInteger sessionMaxNum;

@property (nonatomic, weak) id<RvsStreamerInitHelperDelegate> delegate;

/**
 *  快速获取初始化单例对象
 *
 *  @return 单例对象
 */
+ (RvsStreamerInitHelper *)streamerInitHelper;

/**
 *  设置配置及缓存路径
 *
 *  @param workPath     配置路径    如果为nil则采用默认
 *  @param cachePath    缓存路径    如果为nil则采用默认
 *  @param appVersion   APP版本号   如果为nil则采用默认
 *
 *  @return 设置结果
 */
- (NSInteger)setStreamerWithWorkPath:(NSString *)workPath cachePath:(NSString *)cachePath appVersion:(NSString *)appVersion;

/**
 *  设置授权信息
 *
 *  @param companyID  公司ID，申请开发者时会提供给开发者
 *  @param companyKey 公司Key，申请开发者时会提供给开发者
 *  @param appID      应用ID，申请开发者时会提供给开发者
 *  @param license    软件许可证，申请开发者时会提供给开发者
 *
 *  @return 设置结果
 */
- (NSInteger)setLoginInfoWithCompanyID:(NSString *)companyID companyKey:(NSString*)companyKey appID:(NSString *)appID license:(NSString *)license;

/**
 *  登陆到IChano云视频平台
 */
- (void)login;

/**
 * 退出应用时，请调用以释放资源
 */
- (void)logout;

/**
 *  是否输出log 默认是NO
 */
- (void)setLogEnabled:(BOOL)enable;

@end


/**
 *  状态回调delegate， 回调处理相应的的UI操作应切换到主线程
 */
@protocol RvsStreamerInitHelperDelegate <NSObject>

@optional

/**
 *  采集端sdk鉴权过程中发生状态变化
 *
 *  @param authState   观看端鉴权状态
 *  @param errCode      观看端鉴权过程中的错误码
 */
- (void)onAuthResultWithAuthState:(EN_RVS_STREAMER_AUTH_STATE)authState
                          errCode:(EN_RVS_ERR)errCode;

//连接状态通知
- (void)onLoginResultWithLoginState:(EN_RVS_STREAMER_LOGIN_STATE)loginState
                       ProgressRate:(EN_RVS_STREAMER_LOGIN_PROGRESS)progressRate
                            errCode:(EN_RVS_LOGIN_ERR)errCode RVS_DEPRECATED_MSG_ATTRIBUTE("using instead");

//CID变化通知
- (void)onUpdateCID:(unsigned long long)localCID;

//设备名称有变化时通知
- (void)onDeviceNameChange:(NSString *)deviceName;

//用户名与密码更新
- (void)onUpdateUserName:(NSString *)userName pwd:(NSString*)pwd;

- (void)onSession:(unsigned long long)remoteCID StateChange:(EN_RVS_STREAMER_SESSION_STATE)state RVS_DEPRECATED_MSG_ATTRIBUTE("using instead");

- (void)onValueAddedServiceStateChange:(EN_RVS_STREAMER_VALUEADDED_SERVICE_STATE)valueAddedServiceState;

/**
 *  观看端的在线状态通知
 *
 *  @param streamerCID           采集端CID
 *  @param streamerPresenceState 采集端的在线状态
 */
- (void)onRemoteViewer:(unsigned long long)remoteCID
           StateChange:(EN_RVS_REMOTE_VIEWER_STATE)state errCode:(EN_RVS_ERR)errCode;


/**
 * 当用户不允许访问设备是的回调
 *
 @param privacy 不允许访问设备类型
 */
- (void)cannotGetPrivacy:(RvsStreamerPrivacy)privacy;


@end
