//
//  DeviceManager.h
//  BTBeacon
//
//  Created by Francesco Zerbinati on 29/10/15.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Device;

@class DeviceManager;
@protocol BlincoDiscoveryDelegate <NSObject>
- (void) updateDevices;
@end

@interface DeviceManager : NSObject

@property (nonatomic, assign) id<BlincoDiscoveryDelegate> delegate;


@property (strong,nonatomic) Device *thisDevice;
// array of scanned devices
@property (nonatomic,strong) NSMutableArray* scannedDevices;
//@property (nonatomic,strong) NSMutableArray* populatedDevices;

+ (DeviceManager *) shared;
-(void) initDeviceIdentity:(void (^)(void)) completion;
-(void) addDevice:(Device*) device;
-(BOOL) isDevicePresent:(Device*) device;

-(NSArray*) getDevices;

-(void) resetDevices;
- (void) updateDevice:(Device*) device;


@end
