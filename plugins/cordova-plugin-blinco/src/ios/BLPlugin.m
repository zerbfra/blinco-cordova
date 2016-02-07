//  BLPlugin.m
//  Blinco Cordova Plugin
//
//  Created by Francesco Zerbinati on 06/02/16.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.

#import "BLPlugin.h"
#import <BlincoKit/BlincoKit.h>

@interface BLPlugin () <BlincoDelegate,BlincoDiscoveryDelegate>

@end


@implementation BLPlugin

@synthesize callbackId;

- (void)init:(CDVInvokedUrlCommand*) command {
    
    NSLog(@"info: Blinco plugin init called");
    // set callback id
    self.callbackId = command.callbackId;
    
    // set delegates
    [[Blinco manager] setDelegate:self];
    // delegate for device discovery
    [[Blinco manager] setDiscoveryDelegate:self];
    
    // check configuration passed by javascript
    if ([command.arguments count] > 0) {
        
        NSMutableDictionary* options = [command argumentAtIndex:0];
        
        // is every parameter set?
        if([options valueForKey:@"app_name"] && [options valueForKey:@"app_id"] && [options valueForKey:@"app_secret"] && [options valueForKey:@"ble_service"]) {
            
            // check if already running (twice invocation?)
            if(![Blinco manager].isRunning) {
                
                // pass the configuration dictionary
                NSDictionary *config = [options copy];
                [[Blinco manager] configure:config];
                
                // initialize
                [[Blinco manager] initialize];
            }
            
        } else {
            NSLog(@"error: please specify app_name, app_id, app_secret and ble_service for Blinco first");
            [self failWithMessage:@"error: please specify app_name, app_id, app_secret and ble_service for Blinco first"];
        }
        
    } else {
        NSLog(@"error: no arguments provided, please configure Blinco first");
        [self failWithMessage:@"error: no arguments provided, please configure Blinco first"];
    }
    
}

- (void) start:(CDVInvokedUrlCommand*) command {
    NSLog(@"info: Blinco plugin start called");
    self.callbackId = command.callbackId;
    [[Blinco manager] start];
}

- (void) stop:(CDVInvokedUrlCommand*) command {
    NSLog(@"info: Blinco plugin stop called");
    self.callbackId = nil;
    [[Blinco manager] stop];
}

- (void) reset:(CDVInvokedUrlCommand*) command {
    NSLog(@"info: Blinco plugin reset called");
    [[Blinco manager] resetDetecting];
}

- (void) initNotifications {
    [[BLNotification manager] connect];
}

#pragma mark - Blinco delegate

- (void) blincoInitialized:(BOOL)success {
    if(success) {
        NSLog(@"info: Blinco was initialized with success");
        [self successWithMessage:@"info: Blinco was initialized with success"];
    } else {
        NSLog(@"error: Blinco can't initialize");
        [self failWithMessage:@"error: Blinco can't be initialized"];
    }
    
}



#pragma mark - Devices delegate

- (void) updateDevices {
    // when a new device is discovered, I need to update the list of devices
    
    NSArray *devices = [[Blinco manager] getNearbyDevices];
    
    NSLog(@"info: devices found %@",devices);
    
    // convert to a serializable array
    NSMutableArray *result = [NSMutableArray array];
    for (Device *device in devices) {
        
        NSNumber *isMoving = [NSNumber numberWithBool:device.sensors.isMoving];
        NSNumber *direction = [NSNumber numberWithFloat:device.sensors.direction];
        NSNumber *altitude = [NSNumber numberWithFloat:device.sensors.relativeAltitude];
        NSNumber *rssi = [NSNumber numberWithFloat:device.rssi];
        
        NSDictionary *payload = @{@"deviceID": device.deviceID, @"iBeaconUUID": device.iBeaconUUID, @"rssi": rssi, @"mov": isMoving , @"comp":direction , @"alt": altitude};
        
        [result addObject:payload];
    }
    
    
    // send notification message
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArray:result];
    // keep the callback id
    [pluginResult setKeepCallback:[NSNumber numberWithBool:YES]];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.callbackId];
    
    /* alternative? 
     
     NSString *stringData = getStringData(); // however you get it
     [webView stringByEvaluatingJavaScriptFromString:
     [NSString stringWithFormat:@"myJSFunction(%@)", stringData]];
     
     
     altra ancora: loop dal js
     */
    
}

#pragma mark - Reload devices

- (void) forceReload {
    [[Blinco manager] resetDetecting];
}


/* SEND SUCCESS OR FAIL MESSAGES */

-(void)successWithMessage:(NSString *)message
{
    if (self.callbackId != nil)
    {
        CDVPluginResult *commandResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:message];
        [self.commandDelegate sendPluginResult:commandResult callbackId:self.callbackId];
    }
}

-(void)failWithMessage:(NSString *)message
{
    CDVPluginResult *commandResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:message];
    
    [self.commandDelegate sendPluginResult:commandResult callbackId:self.callbackId];
}

@end
