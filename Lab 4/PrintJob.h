#ifndef __PRINTJOB_H
#define __PRINTJOB_H

using namespace std;

class PrintJob {
 public:
  PrintJob(int priority, int jobNumber, int pages);
  int getPriority() const;
  int getJobNumber() const;
  int getPages() const;
  // You can add additional functions here

 private:
  int priority_;
  int jobNumber_;
  int numPages_;
};
#endif