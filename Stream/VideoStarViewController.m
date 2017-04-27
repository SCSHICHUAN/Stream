//
//  VideoStarViewController.m
//  Stream
//
//  Created by SHICHUAN on 2017/4/27.
//  Copyright © 2017年 SHICHUAN. All rights reserved.
//

#import "VideoStarViewController.h"
#import <Rvs_Streamer/Rvs_Streamer_API.h>

@interface VideoStarViewController ()

@property (nonatomic,strong) RvsMediaSurfaceView* surfaceView;
@property (nonatomic,strong) UIView* videoView;
@property (nonatomic,strong) UILabel* recordStatus;


@end

@implementation VideoStarViewController


- (id)init{
    self = [super init];
    if (self) {
        [[RvsObserverCenter defaultCenter] addObserver:self];
    }
    return self;
}

- (void)dealloc{
    [[RvsObserverCenter defaultCenter] removeObserver:self];
}



- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"采集端画面";
    
    self.surfaceView = [[RvsMediaSurfaceView alloc] init];
    self.videoView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height/2)];
    [self.view addSubview:self.videoView];
    //此接口需要保证传入的view有固定大小，否则layer显示不出来
    [self.surfaceView videoShowWithView:self.videoView];
    
//    UIBarButtonItem* setting = [[UIBarButtonItem alloc] initWithTitle:@"设置" style:UIBarButtonItemStylePlain target:self action:@selector(settingAction:)];
//    self.navigationItem.rightBarButtonItem = setting;
    
    [self.surfaceView setVideoParamWithBitrate:RvsStreamResolution720p frameRate:15 iFrameInterval:2];
    
//    [self setupSubviews];
    
     [[UIApplication sharedApplication] setIdleTimerDisabled:YES];//屏幕常亮
    
    
    
}

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    self.surfaceView.isPortrait = YES;
    [self.surfaceView openCamera];
}

- (void)viewDidDisappear:(BOOL)animated{
    [super viewDidDisappear:animated];
    [self.surfaceView closeCamera];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
