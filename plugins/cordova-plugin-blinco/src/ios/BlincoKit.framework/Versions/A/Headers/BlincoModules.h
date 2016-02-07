//
//  BlincoModules.h
//  BlincoKit
//
//  Created by Francesco Zerbinati on 16/11/15.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BlincoModules : NSObject


+ (BlincoModules *) manager;


// booleans to tell wich module are active

@property BOOL userModule;

@end
