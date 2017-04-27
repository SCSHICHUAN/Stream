//
//  AppDelegate.m
//  Stream
//
//  Created by SHICHUAN on 2017/4/27.
//  Copyright © 2017年 SHICHUAN. All rights reserved.
//

#import "AppDelegate.h"
#import <Rvs_Streamer/Rvs_Streamer_API.h>
#define K_COMPANY_ID   @"f83cba96bfa24bedb49b58e55749f0f0"
#define K_COMPANY_KEY  @"1469094063851"
#define K_APP_ID       @"31122017042709530001491447501161"
#define K_LICENSE      @"MARA160924"


@interface AppDelegate ()<RvsStreamerInitHelperDelegate>

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    // 获取RvsStreamerInitHelper单例
    RvsStreamerInitHelper *helper = [RvsStreamerInitHelper
                                     streamerInitHelper];
    // 设置代理
    helper.delegate = self;
    
    
    //设置Config文件、record文件路径、APP版本
    //workPath:表示sdk生成的配置文件存储路径 如果为nil则采用默认
    //cachePath:表示sdk log文件存储路径 如果为nil则采用默认
    //appVersion:表示App版本 如果为nil则采用默认
    [helper setStreamerWithWorkPath:nil cachePath:
     nil appVersion :nil];
    
    // 设置sdk参数，CompanyID、CompanyKey、AppID、License（需要去官网申请）
    [helper setLoginInfoWithCompanyID:K_COMPANY_ID companyKey:K_COMPANY_KEY appID:K_APP_ID license:K_LICENSE];
    
    [helper login];
    
    return YES;
}

//采集端sdk登录过程中发生状态变化、错误、登录进度通知
- (void)onAuthResultWithAuthState:(EN_RVS_STREAMER_AUTH_STATE)authState
                          errCode:(EN_RVS_ERR)errCode
{
    NSLog(@"errCode= [ %u ]",errCode);
    NSLog(@"authState = [ %u ]",authState);
}




@end
