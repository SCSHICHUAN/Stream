//
//  MainController.m
//  Stream
//
//  Created by SHICHUAN on 2017/4/27.
//  Copyright © 2017年 SHICHUAN. All rights reserved.
//


#define K_COMPANY_ID   @"f83cba96bfa24bedb49b58e55749f0f0"
#define K_COMPANY_KEY  @"1469094063851"
#define K_APP_ID       @"31122017042709530001491447501161"
#define K_LICENSE      @"MARA160924"


#import "MainController.h"
#import <Rvs_Streamer/Rvs_Streamer_API.h>
#import "ShowCIDuserPasswordController.h"
#import "VideoStarViewController.h"


@interface MainController ()<RvsStreamerInitHelperDelegate>
@property(nonatomic,strong)RvsMediaSurfaceView *mediaSurfaceView;
@property(nonatomic,strong)UIView *videoView;
@property (nonatomic,strong) NSArray* items;
@property (nonatomic,strong) NSMutableSet* viewerCIDs;
@end

@implementation MainController






- (void)viewDidLoad {
    [super viewDidLoad];
   
//    self.items = @[@[@"采集端状态"],@[@"显示CID信息",@"修改用户名密码",@"观看端连接列表",@"采集摄像头视频",@"自定义命令",@"报警/定时录制信息"]];
    self.items = @[@[@"采集端状态"],@[@"打开iPhone摄像头"]];
    self.title = @"登录";
    
    //初始化SDK
    [self setupRvsStreamer];

}
- (void)setupRvsStreamer{
    [[RvsStreamerInitHelper streamerInitHelper] setStreamerWithWorkPath:nil cachePath:nil appVersion:nil];
    [[RvsStreamerInitHelper streamerInitHelper] setLoginInfoWithCompanyID:K_COMPANY_ID companyKey:K_COMPANY_KEY appID:K_APP_ID license:K_LICENSE];
    [[RvsStreamerInitHelper streamerInitHelper] login];
    
#ifdef DEBUG
    [[RvsStreamerInitHelper streamerInitHelper] setLogEnabled:YES];
#endif
    
    [RvsStreamerInitHelper streamerInitHelper].delegate = self;
    
    
    [[RvsObserverCenter defaultCenter] addObserver:self];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return self.items.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.items[section] count];
}

- (UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    static NSString* cellIdentifier = @"CellIdentifier";
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:cellIdentifier];
    }
    if (indexPath.section) {
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
        cell.selectionStyle = UITableViewCellSelectionStyleDefault;
    }
    else{
        cell.accessoryType = UITableViewCellAccessoryNone;
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    cell.textLabel.text = self.items[indexPath.section][indexPath.row];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    NSString* item = self.items[indexPath.section][indexPath.row];
    if ([item isEqualToString:@"显示CID信息"]) {
        ShowCIDuserPasswordController* basic = [[ShowCIDuserPasswordController alloc] initWithStyle:UITableViewStyleGrouped];
        [self.navigationController pushViewController:basic animated:YES];
    }
    else if ([item isEqualToString:@"修改用户名密码"]){
//        SDModifyUserPwdController* modify = [[SDModifyUserPwdController alloc] initWithStyle:UITableViewStyleGrouped];
//        [self.navigationController pushViewController:modify animated:YES];
    }
    else if ([item isEqualToString:@"观看端连接列表"]){
//        SDViewerListController* list = [[SDViewerListController alloc] initWithStyle:UITableViewStyleGrouped];
//        list.viewers = self.viewerCIDs.allObjects;
//        [self.navigationController pushViewController:list animated:YES];
    }
    else if([item isEqualToString:@"打开iPhone摄像头"]){
        VideoStarViewController* real = [[VideoStarViewController alloc] init];
        [self.navigationController pushViewController:real animated:YES];
        real.navigationItem.rightBarButtonItem.title = @"关闭摄像头";
    }
    else if ([item isEqualToString:@"报警/定时录制设置"]){
//        SDSettingController* set = [[SDSettingController alloc] initWithStyle:UITableViewStyleGrouped];
//        [self.navigationController pushViewController:set animated:YES];
    }
    else if ([item isEqualToString:@"自定义命令"]){
//        SDCmdListController* cmd = [[SDCmdListController alloc] initWithStyle:UITableViewStyleGrouped];
//        cmd.receiverID = [[self.viewerCIDs.allObjects firstObject] longLongValue];
//        [self.navigationController pushViewController:cmd animated:YES];
    }
    else if ([item isEqualToString:@"报警/定时录制信息"]){
//        SDSettingController* setting = [[SDSettingController alloc] initWithStyle:UITableViewStyleGrouped];
//        [self.navigationController pushViewController:setting animated:YES];
    }
}

#pragma mark InitHelperDelegate
- (void)onAuthResultWithAuthState:(EN_RVS_STREAMER_AUTH_STATE)authState errCode:(EN_RVS_ERR)errCode{
    dispatch_async(dispatch_get_main_queue(), ^{
        UITableViewCell* cell = [self.tableView  cellForRowAtIndexPath:[NSIndexPath indexPathForRow:0 inSection:0]];
        switch (authState) {
            case EN_RVS_STREAMER_AUTH_STATE_INIT:
                cell.detailTextLabel.text = @"初始化中";
                cell.detailTextLabel.textColor = [UIColor grayColor];
                break;
            case EN_RVS_STREAMER_AUTH_STATE_CONNECTING:
                cell.detailTextLabel.text = @"连接中...";
                cell.detailTextLabel.textColor = [UIColor grayColor];
                break;
            case EN_RVS_STREAMER_AUTH_STATE_DEVICE_AUTHORIZED:
                cell.detailTextLabel.text = @"设备鉴权中...";
                cell.detailTextLabel.textColor = [UIColor grayColor];
                break;
            case EN_RVS_STREAMER_AUTH_STATE_SUCCESS:
                cell.detailTextLabel.text = @"已连接";
                cell.detailTextLabel.textColor = [UIColor greenColor];

                break;
            case EN_RVS_STREAMER_AUTH_STATE_FAIL:
                cell.detailTextLabel.text = @"连接错误";
                cell.detailTextLabel.textColor = [UIColor redColor];
                break;
            default:
                break;
        }
    });
}


- (void)onRemoteViewer:(unsigned long long)remoteCID StateChange:(EN_RVS_REMOTE_VIEWER_STATE)state errCode:(EN_RVS_ERR)errCode{
    
    if (!_viewerCIDs) {
        _viewerCIDs = [[NSMutableSet alloc] init];
    }
    [_viewerCIDs addObject:@(remoteCID)];
    
    dispatch_async(dispatch_get_main_queue(), ^{
//        MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
//        hud.mode = MBProgressHUDModeText;
//        hud.label.text = [NSString stringWithFormat:@"有观看端接入CID:%llu",remoteCID];
//        [hud hideAnimated:YES afterDelay:1.f];
    });
}

- (void)onUpdateCID:(unsigned long long)localCID{
    dispatch_async(dispatch_get_main_queue(), ^{
//        MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
//        hud.mode = MBProgressHUDModeText;
//        hud.label.text = @"CID已更新";
//        [hud hideAnimated:YES afterDelay:1.f];
    });
}

- (void)onDeviceNameChange:(NSString *)deviceName{
    dispatch_async(dispatch_get_main_queue(), ^{
//        MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
//        hud.mode = MBProgressHUDModeText;
//        hud.label.text = @"设备名称已更新";
//        [hud hideAnimated:YES afterDelay:1.f];
    });
}
















- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    return;
}


@end
