#include "PrintJob.h"

PrintJob::PrintJob(int priority, int jobNumber, int numPages)
    : priority_(priority), jobNumber_(jobNumber), numPages_(numPages) {}

int PrintJob::getPriority() const { return priority_; }

int PrintJob::getJobNumber() const { return jobNumber_; }

int PrintJob::getPages() const { return numPages_; }