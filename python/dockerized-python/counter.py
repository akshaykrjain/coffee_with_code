import time

counter = 1

while True:
    print("hello..#" + str(counter))
    counter += 1
    if counter > 100:
        counter = 1
    time.sleep(1)
