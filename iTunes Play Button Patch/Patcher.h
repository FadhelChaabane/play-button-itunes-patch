//
//  Patcher.h
//  iTunes Play Button Patch
//
//  Created by Farhan Ahmad on 11/12/14.
//  Copyright (c) 2014 Farhan Ahmad. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RcdFile.h"

//static NSString * const RCD_PATH = @"/Users/thebitguru/Documents/Development/Projects/play-button-itunes-patch/rcd";
static NSString * const RCD_PATH = @"/System/Library/CoreServices/rcd.app/Contents/MacOS/";

@interface Patcher : NSObject

typedef NS_ENUM(NSInteger, SIPStatus) {
    SIPStatusEnabled,
    SIPStatusDisabled,
    SIPStatusCSRUTILNotFound
};

@property NSMutableArray* files;
@property NSMutableArray * backupFiles;
@property BOOL isMainFilePatched;
@property BOOL areCommandLineToolsInstalled;
@property SIPStatus SystemIntegrityProtectionStatus;

- (id) init;
- (BOOL) isFilePatched: (NSString *) filePath;
- (void) reloadFiles;
- (BOOL) patchFile: (NSError **) error;
- (void) restoreFromBackupFile:(RcdFile *)fileToRestore;
- (BOOL) restartRcdProcesses;

@end
