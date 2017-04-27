//
//  RvsObserverCenter.h
//  Rvs_Viewer
//
//  Created by 田祥根 on 2016/9/21.
//  Copyright © 2016年 ifziv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Rvs_Streamer.h"

/**
 RvsObserverCenter类主要用于回调消息的分发
 */
@interface RvsObserverCenter : NSObject <Rvs_Streamer_Media_Record_Delegate,
                                        Rvs_Streamer_Media_MotionDetect_Delegate,
                                        Rvs_Streamer_Cmd_Delegate>

+ (instancetype)defaultCenter;


- (void)addObserver:(id)observer;


- (void)removeObserver:(id)observer;

@end
