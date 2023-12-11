import logging
import time
import random

# Configure logging
logging.basicConfig(format='%(asctime)s - %(levelname)s - %(message)s', level=logging.INFO)

counter = 1

while True:
    if counter <= 90:
        log_level = logging.INFO
    elif 90 < counter <= 95:
        log_level = logging.WARNING
    else:
        log_level = logging.ERROR

    logging.log(log_level, "hello..#" + str(counter))
    counter += 1
    if counter > 100:
        counter = 1

    # Generate a random sleep duration between 1 to 5 seconds
    sleep_duration = random.uniform(1, 5)
    time.sleep(sleep_duration)
