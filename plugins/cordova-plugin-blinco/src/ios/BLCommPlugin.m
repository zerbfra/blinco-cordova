//  BLCommPlugin.m
//  Blinco Cordova Plugin
//
//  Created by Francesco Zerbinati on 06/02/16.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.

#import "BLCommPlugin.h"
#import <BlincoKit/BlincoKit.h>

@interface BLCommPlugin ()

@end


@implementation BLCommPlugin

@synthesize callbackId;

- (void)connect:(CDVInvokedUrlCommand*) command {
    
    NSLog(@"info: Blinco Push plugin connect called");
    
    self.callbackId = command.callbackId;
    
    [[BLNotification manager] connect];
    [[BLNotification manager] setBLNotificationHandler:self method:@selector(receivedMessage:)];
    
}

- (void) send:(CDVInvokedUrlCommand*) command {
    NSLog(@"info: Blinco plugin send called");
    
    
    // check if blinco was initialized
    if([Blinco manager].isRunning) {
        
        // check configuration passed by javascript
        if ([command.arguments count] > 0) {
            
            NSMutableDictionary* options = [command argumentAtIndex:0];
            
            // is every parameter set?
            if([options valueForKey:@"message"] && [options valueForKey:@"target"]) {
                
                NSString *text = [options valueForKey:@"message"];
                
                Device *target = [[Device alloc] init];
                target.deviceID = [options valueForKey:@"target"];
                
                BLMessage *message = [[BLNotification manager] createMessage:@"ChatMessage" payload:@{@"chat":text}];
                
                [[BLNotification manager] publish:message onDevice:target];
                
                NSString *log = [NSString stringWithFormat:@"info: blinco communication payload sent to %@",target.deviceID];
                CDVPluginResult *commandResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:log];
                [self.commandDelegate sendPluginResult:commandResult callbackId:command.callbackId];
            } else {
                CDVPluginResult *commandResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"error: message and target required"];
                [self.commandDelegate sendPluginResult:commandResult callbackId:command.callbackId];
            }
        } else {
            CDVPluginResult *commandResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"error: message and target required"];
            [self.commandDelegate sendPluginResult:commandResult callbackId:command.callbackId];
        }
    } else {
        NSLog(@"fatal error: can't send blinco messages if blinco is not initialized");
        CDVPluginResult *commandResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"error: blinco must be initialized before calling blinco communication!"];
        [self.commandDelegate sendPluginResult:commandResult callbackId:command.callbackId];
    }
    
    
}


#pragma mark - Message delegates

- (void) receivedMessage:(NSNotification*) notification {
    
    NSLog(@"info: received a new blinco communication payload");
    
    BLMessage* message = notification.object;
    if([message.type isEqualToString:@"ChatMessage"]) {
        // message content is: chat
        NSString *msg = [message.payload objectForKey:@"chat"];
        
        // create a dictionary to pass to js
        NSDictionary *result = @{@"from":message.from, @"message": msg};
        
        // send notification message
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:result];
        // keep the callback id
        [pluginResult setKeepCallback:[NSNumber numberWithBool:YES]];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:self.callbackId];
        
    }
    
}

@end
