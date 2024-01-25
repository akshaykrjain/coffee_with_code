import logging
import time
import random


# Function to generate random Docker-like user names
def generate_user_name():
    adjectives = ["nostalgic", "focused", "vibrant", "serene", "mystic"]
    animals = ["swan", "turing", "giraffe", "elephant", "parrot"]
    return f"{random.choice(adjectives)}_{random.choice(animals)}"


# Create a logger instance
logger = logging.getLogger()
logger.setLevel(logging.INFO)

# Configure logging with JSON formatter
log_formatter = logging.Formatter(
    '{"timestamp": "%(asctime)s", "level": "%(levelname)s", "user": "%(user)s", "message": "%(message)s"}'
)
console_handler = logging.StreamHandler()
console_handler.setFormatter(log_formatter)
logger.addHandler(console_handler)

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

    # Log message with user name
    logger.log(log_level, log_message, extra={"user": user_name})

    counter += 1
    if counter > 100:
        counter = 1

    # Generate a random sleep duration between 1 to 5 seconds
    sleep_duration = random.uniform(1, 5)
    time.sleep(sleep_duration)
