//
//  MQTTHandler.h
//  BlincoKit
//
//  Created by Francesco Zerbinati on 18/11/15.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Device;

typedef enum {
    BLMessageDevice = 0,
    BLMessageChat,
    BLMessageRequest,
} BLMessage;

@interface MQTTHandler : NSObject

+ (MQTTHandler *) call;

- (void) connect;

- (void) publishDictionary:(NSDictionary*) dictionary onDevice: (Device*) device;

- (NSDictionary*) createMessage:(BLMessage) type payload:(NSDictionary*) payload;

@end
