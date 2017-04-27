//
//  ShowCIDuserPasswordController.m
//  Stream
//
//  Created by SHICHUAN on 2017/4/27.
//  Copyright © 2017年 SHICHUAN. All rights reserved.
//

#import "ShowCIDuserPasswordController.h"
#import <Rvs_Streamer/Rvs_Streamer_API.h>

@interface ShowCIDuserPasswordController ()
@property (nonatomic,strong) NSArray* items;
@end

@implementation ShowCIDuserPasswordController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = @"CID信息";
    self.items = @[@"CID",@"用户名",@"密码",@"二维码"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {

    return self.items.count;;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    static NSString* cellIdentifier = @"CellIdentifier";
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:cellIdentifier];
    }
    NSString* item = self.items[indexPath.row];
    cell.textLabel.text = item;
    if ([item isEqualToString:@"CID"]) {
        cell.detailTextLabel.text = [NSString stringWithFormat:@"%llu",[Rvs_Streamer defaultStreamer].CID];
    }
    else if ([item isEqualToString:@"用户名"]){
        cell.detailTextLabel.text = [Rvs_Streamer defaultStreamer].userName;
    }
    else if ([item isEqualToString:@"密码"]){
        cell.detailTextLabel.text = [Rvs_Streamer defaultStreamer].pwd;
    }
    else if ([item isEqualToString:@"二维码"]){
        cell.accessoryType =UITableViewCellAccessoryDisclosureIndicator;
    }
    return cell;
}


/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    } else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath {
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
