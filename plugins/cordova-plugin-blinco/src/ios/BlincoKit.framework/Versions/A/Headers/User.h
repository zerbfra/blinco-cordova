//
//  User.h
//  BTBeacon
//
//  Created by Francesco Zerbinati on 12/11/15.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface User : NSObject

@property (strong,nonatomic) NSString *userID;
@property (strong,nonatomic) NSString *name;
@property (strong,nonatomic) NSString *surname;
@property (strong,nonatomic) NSString *mail;
@property (strong,nonatomic) NSString *password;

@property (strong,nonatomic) NSMutableArray *devices;

- (NSString *) description;
- (NSString *) fullName;

@end
