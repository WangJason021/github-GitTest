import time
import threading

def print_time(ThreadName, Delay):
    count = 0
    while count < 5:
        time.sleep(Delay)
        count = count + 1
        print("%s: %s" % (ThreadName, time.ctime(time.time())))

