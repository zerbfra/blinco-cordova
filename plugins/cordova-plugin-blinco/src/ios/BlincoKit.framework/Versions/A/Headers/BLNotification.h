//
//  BLNotification.h
//  BlincoKit
//
//  Created by Francesco Zerbinati on 18/11/15.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLMessage.h"

@class Device;

@interface BLNotification : NSObject

@property BOOL isConnected;

+ (BLNotification *) manager;

- (void) connect;

- (void) publish:(BLMessage*) message onDevice: (Device*) device;

- (void) publishThisDeviceTo:(Device*) to;

- (BLMessage*) createMessage:(NSString*) type payload:(NSDictionary*) payload;


- (void) setBLNotificationHandler:(id) istance method:(SEL) method;
- (void) setBLDeviceNotificationHandler:(id) istance method:(SEL) method;

- (void) sendPush:(NSString*) title withPayload:(NSDictionary*) payload to:(Device*) to;


@end
