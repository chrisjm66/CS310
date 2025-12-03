#include "HealthTracker.h"

using namespace std;

int main() {
	HealthTracker* tracker = new HealthTracker();
	tracker->execute();

	delete tracker;
}