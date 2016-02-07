//
//  Blinco.h
//  BTBeacon
//
//  Created by Francesco Zerbinati on 25/10/15.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h> 

#import "DeviceManager.h"
#import "UserManager.h"
#import "Device.h"
#import "User.h"

#import "BlincoModules.h"

#import "BLNotification.h"

@protocol BlincoDelegate <NSObject>
- (void) blincoInitialized:(BOOL)success;
@end

@protocol BlincoGPSDelegate <NSObject>
- (void) GPSPositionFoundAtLat: (float)lat andLon:(float)lon;
@end

@protocol BlincoiBeaconDelegate <NSObject>
- (void) ranging:(NSString*) beaconID withRSSI:(NSInteger) rssi;
@end

@interface Blinco : NSObject

#pragma mark - Instance
+(Blinco *) manager;
- (void) configure:(NSDictionary*) config;
- (void) initialize;
- (void) start;
- (void) stop;

#pragma mark - Public properties

@property (strong,nonatomic) id<BlincoDelegate> delegate;
@property BOOL configured;
@property (strong,nonatomic) NSString *appName;
@property (strong,nonatomic) NSString *appId;
@property (strong,nonatomic) NSString *appSecret;
@property (strong,nonatomic) NSString *bleUUID;
@property BOOL isRunning;


#pragma mark - Delegate assignement

- (void) setiBeaconDelegate: (id<BlincoiBeaconDelegate>) instance;
- (void) setDiscoveryDelegate:(id<BlincoDiscoveryDelegate>)instance;
- (void) setUserDelegate: (id<BlincoUserDelegate>) instance;
- (void) setGPSDelegate:(id<BlincoGPSDelegate>)instance;

#pragma mark - Methods

- (NSArray*) getNearbyDevices;


/* BLE + MPC + Motion combined methods */
- (void) startDetecting;
- (void) stopDetecting;
- (void) resetDetecting;

/* BLE methods */
- (void) BLEStart;
- (void) BLEStop;
- (void) BLEReset;

/* MPC methods */
-(void) MPCStart;
-(void) MPCStop;
-(void) MPCReset;

/* iBeacon methods */
- (void) iBeaconBroadcastStart;
- (void) iBeaconBroadcastStop;

- (void) startRangeiBeacon:(NSString*) iBeaconTarget;
- (void) stopRangeiBeacon;

/* Motion methods */
- (void) motionStart;
- (void) motionStop;

/* GPS methods */
- (void) getGPSPosition;

/* Notifications methods */
- (void) enableNotifications;
- (void) setPushNotificationToken:(NSData*) token;
- (void) managePushNotification:(NSDictionary*) notificationInfo;
- (void) sendLocalNotification:(Device*) newDevice withMessage:(NSString*) msg;


@end
