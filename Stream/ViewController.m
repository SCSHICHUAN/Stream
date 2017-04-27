//
//  ViewController.m
//  Stream
//
//  Created by SHICHUAN on 2017/4/27.
//  Copyright © 2017年 SHICHUAN. All rights reserved.
//

#import "ViewController.h"
#import <Rvs_Streamer/Rvs_Streamer_API.h>

@interface ViewController ()
@property(nonatomic,strong)RvsMediaSurfaceView *mediaSurfaceView;
@property(nonatomic,strong)UIView *videoView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.videoView = [[UIView alloc] initWithFrame:self.view.bounds];
   [self.view.layer addSublayer:self.videoView.layer];
    self.videoView.backgroundColor = [UIColor lightGrayColor];
    
    // Do any additional setup after loading the view, typically from a nib.
    self.mediaSurfaceView = [[RvsMediaSurfaceView alloc] init];
//    //获取采集端视频画面
   [self.mediaSurfaceView videoShowWithView:self.videoView];
//    // 如需设置视频参数请调用下面的方法
//    [self.mediaSurfaceView openCameraWithResolution: RvsStreamResolution720p];
    //打开摄像头设置分辨率(默认采用480p)
    [self.mediaSurfaceView openCamera];
//    [self.view.layer addSublayer:[self.mediaSurfaceView getPreviewLayerWithFrame:self.view.bounds]];
    
    
    
 
    
}















-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    //开启本地视频录制
    [self.mediaSurfaceView startRecord];
}



- (void)invokeCamera:(UIButton *)button{
    UIImagePickerController *imagePick = [[UIImagePickerController alloc] init];
    [self presentViewController:imagePick animated:YES completion:^{
        
        // 判断是否有后置摄像头
        //        UIImagePickerControllerCameraDeviceFront ,为前置摄像头
        BOOL iscamera = [UIImagePickerController isCameraDeviceAvailable:UIImagePickerControllerCameraDeviceRear];
        if (!iscamera) {
            NSLog(@"没有摄像头");
            return ;
        }
        
        imagePick.sourceType = UIImagePickerControllerSourceTypeCamera;
        imagePick.allowsEditing = YES; //拍完照可以进行编辑
        
        
        
    }];
    
    
    
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    return;
}


@end
