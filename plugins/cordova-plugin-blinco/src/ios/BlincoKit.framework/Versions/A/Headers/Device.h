//
//  Device.h
//  BTBeacon
//
//  Created by Francesco Zerbinati on 25/10/15.
//  Copyright © 2015 Francesco Zerbinati. All rights reserved.
//

#import <Foundation/Foundation.h>

@class User;

struct DeviceSensors {
    BOOL isMoving;
    float direction;
    float relativeAltitude;
};

typedef enum {
    DetectorRangeUnknown = 0,
    DetectorRangeFar,
    DetectorRangeNear,
    DetectorRangeImmediate,
    DetectorRangeErr,
} DetectorRange;

@interface Device : NSObject

- (NSString *)description;

@property (strong,nonatomic) NSString *deviceID;

@property (strong,nonatomic) NSString *iBeaconUUID;

@property (strong,nonatomic) NSString *pushToken;

@property (strong,nonatomic) NSString *targetID;

@property (nonatomic) float rssi;

@property (nonatomic) float targetRssi;

@property (nonatomic,assign) struct DeviceSensors sensors;  // actual measurement
@property (nonatomic,assign) struct DeviceSensors prevSensors; // previous measurement

@property (strong,nonatomic) User *user;

- (void) setMovement:(BOOL) isMoving;
- (void) setDirection:(float) direction;
- (void) setAltitude:(float) altitude;

- (BOOL) getMovement;
- (float) getDirection;
- (float) getAltitude;

- (DetectorRange) calculateRange;

- (struct DeviceSensors) getMotionData;
- (void) setPrevMotionData:(struct DeviceSensors) prevSensors;
- (BOOL) needsUpdate;
- (void) updateDeviceInfo;

- (NSDictionary*) createPayload;

@end
