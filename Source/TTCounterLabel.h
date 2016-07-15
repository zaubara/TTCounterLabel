//
//  TTCounterLabel.h
//  TTCounterLabel
//
//  Created by Ross Gibson on 10/10/2013.
//  Copyright (c) 2013 Triggertrap. All rights reserved.
//

@import TTTAttributedLabel;

typedef NS_ENUM(NSInteger, kCountDirection){
    kCountDirectionUp = 0,
    kCountDirectionDown
};

typedef NS_ENUM(NSInteger, kDisplayMode) {
    kDisplayModeFull = 0,
    kDisplayModeSeconds = 1
};

#pragma mark - TTCounterLabelDelegate

@class TTCounterLabel;

@protocol TTCounterLabelDelegate <NSObject>
@optional
- (void)countdownDidEndForSource:(TTCounterLabel *)source;
- (void)secondsRemainingForCountdown:(long)secondsToZero;


@end

#pragma mark - TTCounterLabel

@interface TTCounterLabel : TTTAttributedLabel

@property (weak) id <TTCounterLabelDelegate> countdownDelegate;
@property (assign, nonatomic) unsigned long long currentValue;
@property (assign, nonatomic) unsigned long long startValue;
@property (assign, nonatomic) NSInteger countDirection;
@property (strong, nonatomic) UIFont *boldFont;
@property (strong, nonatomic) UIFont *regularFont;
@property (assign, nonatomic) BOOL isRunning;
@property (assign, nonatomic) kDisplayMode displayMode;

#pragma mark - Block support -
// KJM

/**
 *  Block called when the countdown timer ends.
 */
@property (nonatomic, copy) void (^countdownDidEndForSourceBlock)(TTCounterLabel *source);

/**
 *  Block to receives seconds remaining for the timer.
 */
@property (nonatomic, copy) void (^secondsRemainingForCountdown)(NSNumber *secondsToZero);

/**
 *  Block to check whether the timer is running.
 */
@property (copy, nonatomic) void (^isRunningBlock)(BOOL isRunning);


#pragma mark - Public

- (void)start;
- (void)stop;
- (void)reset;
- (void)updateApperance;

@end
