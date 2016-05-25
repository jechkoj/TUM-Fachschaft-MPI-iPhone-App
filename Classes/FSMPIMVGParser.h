// FSMPI App - Fachschaft für Mathematik, Physik & Informatik TU München
// ---------------------------------------------------------------------
// MVG parser class for public transport departures

#import <Foundation/Foundation.h>

@class FSMPIMVGParser;

@protocol FSMPIMVGParserDelegate
// Sent when departures for a station were found
- (void)mvgParser:(FSMPIMVGParser*)parser didFinishParsingDepartures:(NSArray*)departureDictionaries forStation:(NSString*)stationName;
@optional
// Sent when a request did fail
- (void)mvgParser:(FSMPIMVGParser*)parser didFailWithError:(NSError*)error;
@end

// Parser for MVG-Live for bus and train departure times
@interface FSMPIMVGParser : NSObject
//<NSXMLParserDelegate>
{
	NSString *requestedStationName;
	id<FSMPIMVGParserDelegate>__unsafe_unretained delegate;
}

@property (assign) id<FSMPIMVGParserDelegate>delegate;
@property (strong) NSString *requestedStationName;

// Requests departures for a station
- (void)requestDeparturesForStation:(NSString*)stationName;
// Parses the data from the server
- (void)parseReceivedData:(NSData*)data;

@end