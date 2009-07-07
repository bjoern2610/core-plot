
#import <Foundation/Foundation.h>
#import "CPPlot.h"
#import "CPDefinitions.h"

@class CPLineStyle;
@class CPFill;
@class CPPlotRange;
@class CPColor;
@class CPBarPlot;



extern NSString * const CPBarPlotBindingBarLengths;

typedef enum _CPBarPlotField {
    CPBarPlotFieldBarLength
} CPBarPlotField;

@protocol CPBarPlotDataSource <CPPlotDataSource> 
@optional 
-(CPFill *) barFillForBarPlot:(CPBarPlot *)barPlot recordIndex:(NSNumber *)index; 
@end 

@interface CPBarPlot : CPPlot {
    id observedObjectForBarLengthValues;
    NSString *keyPathForBarLengthValues;
    CPLineStyle *lineStyle;
    CPFill *fill;
    CGFloat barWidth;
    CGFloat barOffset;
    CGFloat cornerRadius;
    NSDecimalNumber *baseValue;
    NSArray *barLengths;
    BOOL barsAreHorizontal;
    CPPlotRange *plotRange;
} 

@property (nonatomic, readwrite, assign) CGFloat barWidth;
@property (nonatomic, readwrite, assign) CGFloat barOffset;     // In units of bar width
@property (nonatomic, readwrite, assign) CGFloat cornerRadius;
@property (nonatomic, readwrite, copy) CPLineStyle *lineStyle;
@property (nonatomic, readwrite, copy) CPFill *fill;
@property (nonatomic, readwrite, assign) BOOL barsAreHorizontal;
@property (nonatomic, readwrite, copy) NSDecimalNumber *baseValue;
@property (nonatomic, readwrite, copy) CPPlotRange *plotRange;

+(CPBarPlot *)tubularBarPlotWithColor:(CPColor *)color horizontalBars:(BOOL)horizontal;

@end
