//
//  Rvs_Streamer.h
//  Rvs_Stream
//
//  Created by Lvyi on 4/21/15.
//  Copyright (c) 2015 ifziv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Rvs_Streamer/Rvs_Streamer_Capacity.h>
#import <Rvs_Streamer/Rvs_Streamer_Media.h>
#import <Rvs_Streamer/Rvs_Streamer_Cmd.h>


typedef enum enum_RVS_STREAMER_LANGUAGE{
    
    E_RVS_STREAMER_LANGUAGE_zh_CN         = 1,
    E_RVS_STREAMER_LANGUAGE_en            = 2,
    E_RVS_STREAMER_LANGUAGE_zh_TW         = 3,
    E_RVS_STREAMER_LANGUAGE_fr            = 4,
    E_RVS_STREAMER_LANGUAGE_ja            = 5,
    E_RVS_STREAMER_LANGUAGE_es            = 6,
    E_RVS_STREAMER_LANGUAGE_ko            = 7,
    E_RVS_STREAMER_LANGUAGE_it            = 8,
    E_RVS_STREAMER_LANGUAGE_pt            = 9,
    E_RVS_STREAMER_LANGUAGE_ru            = 10,
    E_RVS_STREAMER_LANGUAGE_th            = 11,
    E_RVS_STREAMER_LANGUAGE_de            = 12,
    E_RVS_STREAMER_LANGUAGE_ar            = 13,
    E_RVS_STREAMER_LANGUAGE_el            = 14
    
}EN_RVS_STREAMER_LANGUAGE;


typedef enum enum_RVS_STREAMER_AUTH_STATE
{
    
    EN_RVS_STREAMER_AUTH_STATE_INIT       = 0,
    EN_RVS_STREAMER_AUTH_STATE_DEVICE_AUTHORIZED =3, // 设备鉴权,参数有效性查询
    EN_RVS_STREAMER_AUTH_STATE_CONNECTING = 4, // 设备上线操作
    EN_RVS_STREAMER_AUTH_STATE_SUCCESS = 5, // 设备状态成功
    EN_RVS_STREAMER_AUTH_STATE_FAIL = 10,
    
}EN_RVS_STREAMER_AUTH_STATE;


typedef enum enum_RVS_ERR
{
    EN_RVS_SUCESS                           = 0,
    EN_RVS_PAREMETER_ERR                    = 1,
    EN_RVS_DECRESPONSE_ERR                  = 2,
    
    EN_RVS_AUTHER_ERR                       = 1000,
    EN_RVS_AUTHER_PARMETER_ERR              = 1001,// 参数错误       2001
    EN_RVS_AUTHER_VERIFYCODE_ERR            = 1002,// 手机校验码错误 2002
    EN_RVS_AUTHER_APPID_PAR_ERR             = 1003,// APPID正确 应该是license 但是发送了 symbol 2003
    EN_RVS_AUTHER_APPID_FULL_ERR            = 1004,// 总量授权 ， 使用已经满了  2004
    EN_RVS_AUTHER_LICENSE_USED_ERR          = 1005,// license 已经被使用   2005
    EN_RVS_AUTHER_USRINF_ERR                = 1007, // 用户的密码错误      2007
    EN_RVS_AUTHER_REQST_FREQUENTLY          = 1008, //请求过于频繁         2009
    EN_RVS_AUTHER_GETCHECHCODE_ERR          = 1009, // 验证码获取错误       2010
    EN_RVS_AUTHER_DEVCOMPANY_ERR            = 1010, // 产品 属于不同的 企业 2011
    EN_RVS_AUTHER_DEVAPP_ERR                = 1011, //设备不属于同一个 APP  2012
    EN_RVS_AUTHER_DEV_NOTREGST              = 1012, //产品 没有初始化     2013
    
    EN_RVS_AUTHER_EMAIL_HAVEBIND            = 1105, //邮箱已经被绑定  2105
    EN_RVS_AUTHER_EMAIL_HAVEEXIST           = 1106,// 邮箱 已经存在   2106
    EN_RVS_AUTHER_MOBILE_HAVEEXIST          = 1107,//  手机号 已经存在 2107
    EN_RVS_AUTHER_MOBILE_HAVEBIND           = 1108, // 手机号已  绑定   2108
    EN_RVS_AUTHER_VIVERCID_EXIST            = 1109, // 观看端 已经注册   2109
    EN_RVS_AUTHER_STREAMCID_EXIST           = 1110, // 采集端 已经注册    2110
    
    EN_RVS_AUTHER_COMPANY_NOTEXIST          = 1200,// 公司 不存在   2201
    EN_RVS_AUTHER_APPID_NOTEXIST            = 1201,// app 不存在    2202
    EN_RVS_AUTHER_LICENSE_NOTEXIST          = 1202,//鉴权 license 不存在 2203
    EN_RVS_AUTHER_VIEWER_NOTEXIST           = 1203,//鉴权 客户端不存在 (没有 CID) 2204
    EN_RVS_AUTHER_STREMER_NOTEXIST          = 1204,//鉴权 avs 不存在  2205
    EN_RVS_AUTHER_PRODUCT_NOTEXIST          = 1205, //鉴权  产品不存在  2206
    EN_RVS_AUTHER_USR_NOTEXIST              = 1206, //鉴权  用户不存在  2207
    EN_RVS_AUTHER_SESSION_NOTEXIST          = 1207,// 鉴权 中心 session 不存在 2208
    EN_RVS_AUTHER_REGISTQUERYFAILL          = 1208, // 没有 初始化      2014
    EN_RVS_AUTHER_UNKNON                    = 1299,
    
    EN_RVS_USR_LISTNODE_FULL                = 1301, // 用户 添加 数目 过多 4002
    EN_RVS_USR_SIGN_AGAIN                   = 1302, // 用户 重复 签到  4003
    EN_RVS_USR_AVS_EXISTED                  = 1303, // 用户 系统 avs已经存在 4101
    EN_RVS_USR_SESSION_NOTEXIST             = 1304,//   用户 session  不存在 4201
    EN_RVS_USR_ACCOUNT_NOTEXIST             = 1305, // 用户 系统 账号 不存在 4202
    EN_RVS_USR_LIST_NOTEXIST                = 1306, // avs list 中 不存在    4203
    EN_RVS_USR_TASKID_NOTEXIST              = 1307, // 做的 任务 不存在      4204
    EN_RVS_USR_VERSION_MUSTUPDATE           = 1308, // 9000 版本需要强制 升级
    
    EN_RVS_INF_AVS_HAVEBINDBYOUTHER         = 1401, // 信息 系统 设备 已经 被其他设备绑定3002
    EN_RVS_INF_AVS_DSTHAVECLOUD             = 1402, // 目标CID 已经购买 云服务 3003
    EN_RVS_INF_AVS_SRCONCLOUD               = 1403, // 源 cid 没有 云服务      3004
    EN_RVS_INF_AVS_ENFORCE_BIND             = 1412,
    EN_RVS_INF_STREAMER_NOTEXIST            = 1413,// 信息系统 采集端不存在   3201
    EN_RVS_INF_VIEWER_NOTEXIST              = 1414,//观看端不存在3202
    
    EN_RVS_INF_STREAMER_CAP_NOTEXIST        = 1415,//  能力集合不存在 3203
    EN_RVS_INF_VIEWER_CAP_NOTEXIST          = 1416, //                3204
    
    EN_RVS_INF_STREAMER_SUP_NOTEXIST        = 1417,  //支持项 不存在   3205
    EN_RVS_INF_VIEWER_SUP_NOTEXIST          = 1418,// 3206
    
    EN_RVS_INF_STREAMER_BUS_NOTEXIST        = 1419,// 业务项 不支持 3207
    EN_RVS_INF_VIEWER_BUS_NOTEXIST          = 1420,//3208
    
    EN_RVS_INF_STREAMER_SERVICE_NOTEXIST    = 1421,// 服务 不存在 3209
    EN_RVS_INF_VIEWER_SERVICE_NOTEXIST      = 1422,
    
    EN_RVS_SERVER_SYSTERM_ERR               = 1999, // 系统 错误
    EN_RVS_NET_ERR                          = 2000,
    EN_RVS_NET_SOCKET_ERR                   = 2001, // socket 创建失败
    EN_RVS_NET_TIMEOUT                      = 2002, // connect 上 但是超时 没有回应
    EN_RVS_NET_CONNETERR                    = 2003, // CONNECT 不上
    EN_RVS_NET_RCVDATAERR                   = 2004,
    
    EN_RVS_NET_REGIST_ERR                   = 2011, // 分配 cid 错误
    EN_RVS_NET_ALLOCT_ERR                   = 2012, // cid 与 cpass  不 匹配
    EN_RVS_NET_INTERUPT                     = 2013, // sokect 中断
    EN_RVS_NET_LIVETIMEOUT                  = 2014, // 保活 超时
    
    EN_RVS_PEER_OFFLINE                     = 2100, // 远端没有上线
    EN_RVS_PEER_ERRSECRET                   = 2101, // 添加远端的用户名和 密码 错误
    EN_RVS_PEER_NORIGHT                     = 2102, // 没有 权限
    
    EN_RVS_CFGERR                           = 3000,
    EN_RVS_CFGERR_ENCR                      = 3001,  //加密错误
    EN_RVS_CFGERR_SAVE                      = 3002,  //存文件失败
    EN_RVS_CFGERR_LOAD                      = 3003,  //加载文件失败
    EN_RVS_CFGERR_DECR                      = 3004,  //文件解密失败
    EN_RVS_CFGERR_PARSE                     = 3005,  //文件解析失败
    EN_RVS_CFGERR_TIMEOUT                   = 3006,  //设置配置超时
    EN_RVS_CFGERR_AUTH                      = 3007,  //设置配置权限问题
    EN_RVS_CFGERR_SETERR                    = 3008,  //设置配置错误
    
}EN_RVS_ERR;


typedef enum enum_RVS_REMOTE_VIEWER_STATE {
    
    EN_RVS_PEER_VIEWER_PRESENCE_STATE_INIT       = 0,
    EN_RVS_PEER_VIEWER_PRESENCE_STATE_AUTHER     = 1, // 远端设备鉴权,参数有效性查询
    EN_RVS_PEER_VIEWER_PRESENCE_STATECONNECTED   = 2, // 远端设备上线成功
    EN_RVS_PEER_VIEWER_PRESENCE_STATE_CANUSE     = 3, // 远端设备通道建立
    EN_RVS_PEER_VIEWER_PRESENCE_STATE_FAIL       = 10,
    
}EN_RVS_REMOTE_VIEWER_STATE;


typedef enum enum_RVS_STREAMER_VALUEADDED_SERVICE_STATE{
    E_RVS_STREAMER_VALUEADDED_SERVICE_NOT_PAID = 0,
    E_RVS_STREAMER_VALUEADDED_SERVICE_PAID
}EN_RVS_STREAMER_VALUEADDED_SERVICE_STATE;


typedef enum enum_RVS_LOG_LEVEL
{
    EN_RVS_LOG_LEVEL_DEBUG = 0,
    EN_RVS_LOG_LEVEL_INFO,
    EN_RVS_LOG_LEVEL_WARNNING,
    EN_RVS_LOG_LEVEL_ERROR
    
}EN_RVS_LOG_LEVEL;


typedef enum enum_RVS_STREAMER_LOGIN_STATE
{
    E_RVS_STREAMER_LOGIN_STATE_IDLE      = 0,
    E_RVS_STREAMER_LOGIN_STATE_CONNING   = 1,
    E_RVS_STREAMER_LOGIN_STATE_CONNED    = 2,
    E_RVS_STREAMER_LOGIN_STATE_DISCONNED = 3
}EN_RVS_STREAMER_LOGIN_STATE RVS_DEPRECATED_ATTRIBUTE;

typedef enum enum_RVS_STREAMER_LOGIN_ERR
{
    E_RVS_STREAMER_LOGIN_ERR_NOERR      = 0,
    
    E_RVS_STREAMER_LOGIN_ERR_SERVICEGETERR,
    E_RVS_STREAMER_LOGIN_ERR_AUTH_ERRCOMPANYINFO,
    E_RVS_STREAMER_LOGIN_ERR_AUTH_ERRAPPID,
    E_RVS_STREAMER_LOGIN_ERR_AUTH_ERRLICENSE,
    E_RVS_STREAMER_LOGIN_ERR_AUTH_FULLLICENSE,
    E_RVS_STREAMER_LOGIN_ERR_AUTH_TIMEOUT,
    E_RVS_STREAMER_LOGIN_ERR_CONNECT_ERR,
    E_RVS_STREAMER_LOGIN_ERR_REGISTER_ERR,
    E_RVS_STREAMER_LOGIN_ERR_ALLOCATE_ERR,
    E_RVS_STREAMER_LOGIN_ERR_GETSYSCONFIG_ERR,
    E_RVS_STREAMER_LOGIN_ERR_UPLOADINFO_ERR,
    E_RVS_STREAMER_LOGIN_ERR_CONNECT_INTERUPT,
    E_RVS_STREAMER_LOGIN_ERR_DEFAULT
}EN_RVS_LOGIN_ERR RVS_DEPRECATED_ATTRIBUTE;

typedef enum enum_RVS_STREAMER_LOGIN_PROGRESS{
    E_RVS_STREAMER_LOGIN_PROGRESS_INIT     = 0,
    E_RVS_STREAMER_LOGIN_PROGRESS_SERVICEGET,
    E_RVS_STREAMER_LOGIN_PROGRESS_SERVICEGETTED,
    E_RVS_STREAMER_LOGIN_PROGRESS_AUTHING,
    E_RVS_STREAMER_LOGIN_PROGRESS_AUTHED,
    E_RVS_STREAMER_LOGIN_PROGRESS_CONNECTING,
    E_RVS_STREAMER_LOGIN_PROGRESS_CONNECTED,
    E_RVS_STREAMER_LOGIN_PROGRESS_REGISTING,
    E_RVS_STREAMER_LOGIN_PROGRESS_REGISTED,
    E_RVS_STREAMER_LOGIN_PROGRESS_ALLOCATING,
    E_RVS_STREAMER_LOGIN_PROGRESS_ALLOCATED,
    E_RVS_STREAMER_LOGIN_PROGRESS_GETSYSCONFIG,
    E_RVS_STREAMER_LOGIN_PROGRESS_UPLOADINFO,
    E_RVS_STREAMER_LOGIN_PROGRESS_STARTSERVICES,
    E_RVS_STREAMER_LOGIN_PROGRESS_STARTED
}EN_RVS_STREAMER_LOGIN_PROGRESS RVS_DEPRECATED_ATTRIBUTE;



typedef enum enum_RVS_STREAMER_SESSION_STATE{
    E_RVS_STREAMER_SESSION_STATE_INIT = 0,
    E_RVS_STREAMER_SESSION_STATE_CONNECTING,
    E_RVS_STREAMER_SESSION_STATE_CONNECTED,
    E_RVS_STREAMER_SESSION_STATE_CONNECT_ERROR
}EN_RVS_STREAMER_SESSION_STATE RVS_DEPRECATED_ATTRIBUTE;

@protocol Rvs_Streamer_Delegate <NSObject>


/**
 *  采集端sdk鉴权过程中发生状态变化
 *
 *  @param authState   观看端鉴权状态
 *  @param errCode      观看端鉴权过程中的错误码
 */
- (void)onAuthResultWithAuthState:(EN_RVS_STREAMER_AUTH_STATE)authState
                          errCode:(EN_RVS_ERR)errCode;


/**
 *  观看端的在线状态通知
 *
 *  @param streamerCID           采集端CID
 *  @param streamerPresenceState 采集端的在线状态
 */
- (void)onRemoteViewer:(unsigned long long)remoteCID
         StateChange:(EN_RVS_REMOTE_VIEWER_STATE)state errCode:(EN_RVS_ERR)errCode;


//CID变化通知
- (void)onUpdateCID:(unsigned long long)localCID;

//设备名称有变化时通知
- (void)onDeviceNameChange:(NSString*)deviceName;

//用户名与密码更新
- (void)onUpdateUserName:(NSString*)userName andPwd:(NSString*)pwd;



- (void)onUpdateSymbol:(NSString*)symbol;

- (void)onValueAddedServiceStateChange:(EN_RVS_STREAMER_VALUEADDED_SERVICE_STATE)valueAddedServiceState;

//连接状态通知
- (void)onLoginResultWithLoginState:(EN_RVS_STREAMER_LOGIN_STATE)loginState
                       ProgressRate:(EN_RVS_STREAMER_LOGIN_PROGRESS)progressRate
                            errCode:(EN_RVS_LOGIN_ERR)errCode RVS_DEPRECATED_MSG_ATTRIBUTE("using instead");

- (void)onSession:(unsigned long long)remoteCID StateChange:(EN_RVS_STREAMER_SESSION_STATE)state RVS_DEPRECATED_MSG_ATTRIBUTE("using instead");


@end


@interface Rvs_Streamer : NSObject


@property (nonatomic, copy) NSString* deviceName;//采集端名称
@property (nonatomic, copy, readonly) NSString* userName;//用户名
@property (nonatomic, copy, readonly) NSString* pwd;//密码

@property (nonatomic, assign, readonly)unsigned long long CID;
@property (nonatomic, assign, readonly) NSUInteger sessionCurNum;



/**
*  设置通知回调
*  ps:如果你使用了RvsStreamerInitHelper 初始化SDK，请设置RvsStreamerInitHelperDelegate
*/
@property (nonatomic, assign) id<Rvs_Streamer_Delegate> delegate;


@property (nonatomic, strong, readonly) Rvs_Streamer_Capacity* streamerCapacity;
@property (nonatomic, strong, readonly) Rvs_Streamer_Media* streamerMedia;
@property (nonatomic, strong, readonly) Rvs_Streamer_Cmd* streamerCmd;


+ (Rvs_Streamer*)defaultStreamer;

+ (void)destroy;

- (NSInteger)initStreamerWithWorkPath:(NSString*)workPath
                                  CachePath:(NSString*)cachePath
                                 AppVersion:(NSString*)appVersion;

//设置授权信息
- (NSInteger)setLoginInfoWithCompanyID:(NSString*)companyID
                        CompanyKey:(NSString*)companyKey
                             AppID:(NSString*)appID
                           License:(NSString*)license
                            Symbol:(NSString*)symbol;


/**
 *  设置采集端语言版本
 *
 *  @param language 语言码
 *
 *  @return 0 代表成功，非0代表失败
 */
- (NSInteger)setLanguage:(EN_RVS_STREAMER_LANGUAGE)language;

- (NSInteger)setUserName:(NSString*)userName andPwd:(NSString*)pwd;

- (NSInteger)setSessionMaxNum:(NSUInteger)sessionMaxNum;

- (NSInteger)login;

- (NSInteger)logout;

- (NSString*)getRvsVersion;

- (void)setLogEnabled:(BOOL)enable;

/**
 *  检测观看端和采集端是否在同一个局域网内
 *
 *  @param CID 客户端CID
 *
 *  @return 0 代表是，非0代表否
 */
- (BOOL)checkSameLanNetwork:(unsigned long long)CID;

/**
 *  打印log
 *
 *  @param logLevel : 日志级别
 *           format : 日志格式化字符串
 *  @return NA
 */
- (void)logWithLogLevel:(EN_RVS_LOG_LEVEL)logLevel LogFormat:(NSString *)format, ...;

@end
