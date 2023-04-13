import time
import threading

lock1 = threading.Lock()

def print_time(ThreadName, Delay):
    count = 0
    while count < 5:
        time.sleep(Delay)
        count = count + 1
        print("%s: %s" % (ThreadName, time.ctime(time.time())))

class mt(threading.Thread):
    def __init__(self, threadID, name, delay):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.delay = delay
    def run(self):
        
        print("start:" + self.name)
        lock1.acquire()
        print_time(self.name,self.delay)
        lock1.release()
        print("end:" + self.name)

thread1 = mt(1, "Thread-1", 1)
thread2 = mt(2, "Thread-2", 3)

thread1.start()
thread2.start()
thread1.join()
thread2.join()
print("exit!")