import logging
import time
import random
import json


# Function to generate random Docker-like container names
def generate_user_name():
    adjectives = ["nostalgic", "focused", "vibrant", "serene", "mystic"]
    animals = ["swan", "turing", "giraffe", "elephant", "parrot"]
    return f"{random.choice(adjectives)}_{random.choice(animals)}"


# Configure logging with JSON formatter
logging.basicConfig(format="%(message)s", level=logging.INFO)
log_formatter = logging.Formatter(
    '{"timestamp": "%(asctime)s", "level": "%(levelname)s", "user": "%(user)s", "message": "%(message)s"}'
)
console_handler = logging.StreamHandler()
console_handler.setFormatter(log_formatter)
logging.getLogger().addHandler(console_handler)

counter = 1

while True:
    if counter <= 90:
        log_level = logging.INFO
    elif 90 < counter <= 95:
        log_level = logging.WARNING
    else:
        log_level = logging.ERROR

    user_name = generate_user_name()
    log_message = f"hello from my awesome app..#{counter}"

    # Log message with container name
    logging.log(log_level, log_message, extra={"user": user_name})

    counter += 1
    if counter > 100:
        counter = 1

    # Generate a random sleep duration between 1 to 5 seconds
    sleep_duration = random.uniform(1, 5)
    time.sleep(sleep_duration)
