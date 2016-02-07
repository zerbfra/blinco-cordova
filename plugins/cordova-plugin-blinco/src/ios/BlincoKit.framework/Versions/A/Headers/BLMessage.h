//
//  BLMessage.h
//  BlincoKit
//
//  Created by Francesco Zerbinati on 18/11/15.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BLMessage : NSDictionary

@property (strong,nonatomic) NSString *from;
@property (strong,nonatomic) NSString *type;
@property (strong,nonatomic) NSDictionary *payload;


@end
