//
//  MTOAppDelegate.h
//  CocoaMto
//
//  Created by nakinor on 2014/01/08.
//  Copyright (c) 2014年, 2015年 nakinor. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface MTOAppDelegate : NSObject <NSApplicationDelegate>

@property NSMutableArray *innerDict;
- (id)createDict:(NSString *)dict;
- (NSString *)replaceStringCar:(NSString *)text;
- (NSString *)replaceStringCdr:(NSString *)text;

@property (assign) IBOutlet NSWindow *window;

@property IBOutlet NSTextView *inputTextArea;
@property IBOutlet NSTextView *resultTextArea;

- (IBAction)ClearInput:(id)sender;
- (IBAction)ResultToInput:(id)sender;
- (IBAction)TradOldToModernNew:(id)sender;
- (IBAction)ModernNewToTradOld:(id)sender;
- (IBAction)TradToModern:(id)sender;
- (IBAction)ModernToTrad:(id)sender;
- (IBAction)OldToNew:(id)sender;
- (IBAction)NewToOld:(id)sender;

- (IBAction)writeToFile:(id)sender;
- (IBAction)readFromFile:(id)sender;

@end
