//  BLCommPlugin.h
//  Blinco Cordova Plugin
//
//  Created by Francesco Zerbinati on 06/02/16.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.


#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>
#import <Cordova/CDVPlugin.h>

@interface BLCommPlugin : CDVPlugin


@property (nonatomic, copy) NSString *callbackId;

- (void) connect:(CDVInvokedUrlCommand*) command;
- (void) send:(CDVInvokedUrlCommand*) command;

@end
