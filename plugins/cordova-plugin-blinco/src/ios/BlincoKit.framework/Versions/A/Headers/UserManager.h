//
//  UserManager.h
//  BTBeacon
//
//  Created by Francesco Zerbinati on 12/11/15.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Device;
@class User;

@class UserManager;
@protocol BlincoUserDelegate <NSObject>
- (void) userLogin:(BOOL) success;
@end

@interface UserManager : NSObject

+ (UserManager *) shared;

@property (nonatomic, assign) id<BlincoUserDelegate> delegate;

@property (strong,nonatomic) User *thisUser;
// array of scanned devices

// create/login user: these methods reports to userLogin delegate
- (void) createUserWithMail:(NSString*) mail password:(NSString*)pwd name:(NSString*)name surname:(NSString*)surname;
- (void) loginUserWithMail:(NSString*) mail password:(NSString*) pwd;

// retrieve user
- (void) getUser:(NSString*) userID return:(void (^)(User *)) completion;

// check if user is present on device
- (BOOL) isUserSaved;

@end
