// FSMPI App - Fachschaft für Mathematik, Physik & Informatik TU München
// ---------------------------------------------------------------------
// View controller for public transport departures

#import <UIKit/UIKit.h>
#import "FSMPIMVGParser.h"

@interface FSMPIPubTransportViewController : UIViewController 
<FSMPIMVGParserDelegate, UITableViewDelegate, UITableViewDataSource>
{
	IBOutlet UITableView *departuresTableView;
	IBOutlet UITableViewCell *currentCell;
	
	NSArray *stations;
	NSMutableArray *stationsDepartures;
	BOOL reloadingDepartues;
	BOOL didInitialLoad;
	BOOL didShowErrorAlertView;
	int numberOfParsersInProgress;
	NSTimer *reloadTimer;
}

@property (strong) IBOutlet UITableView* departuresTableView;
@property (nonatomic, weak) IBOutlet UIBarButtonItem *refreshButton;
@property (strong) IBOutlet UITableViewCell *currentCell;
@property (strong) NSTimer *reloadTimer;

-(IBAction)refreshButtonTapped:(id)sender;
- (void)reloadDepartures;
@end