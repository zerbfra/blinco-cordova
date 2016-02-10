//  BLPlugin.h
//  Blinco Cordova Plugin
//
//  Created by Francesco Zerbinati on 06/02/16.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.


#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>
#import <Cordova/CDVPlugin.h>

@interface BLPlugin : CDVPlugin


@property (nonatomic, copy) NSString *inId;
@property (nonatomic, copy) NSString *callbackId;

- (void) init:(CDVInvokedUrlCommand*)command;

- (void) start:(CDVInvokedUrlCommand*) command;
- (void) stop:(CDVInvokedUrlCommand*) command;
- (void) reset:(CDVInvokedUrlCommand*) command;

@end
