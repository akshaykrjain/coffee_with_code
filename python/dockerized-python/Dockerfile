# Use a smaller base image
FROM python:3-alpine as builder

# Set the working directory in the builder stage
WORKDIR /app

# Copy the Python script into the builder stage
COPY counter.py .

# Install any necessary dependencies
# (Note: There are no dependencies for this specific program)
# If your program requires additional packages, add them here using pip

# Install virtualenv
RUN pip install virtualenv

# Create and activate a virtual environment
RUN virtualenv /venv
ENV PATH="/venv/bin:$PATH"

# Install dependencies in the virtual environment
RUN pip install --no-cache-dir boto3
# Switch to a new stage and use a smaller base image
FROM python:3-alpine

# Set the working directory in the final stage
WORKDIR /app

# Copy the program and the virtual environment from the builder stage
COPY --from=builder /app/counter.py /app/
COPY --from=builder /venv /venv

# Set the command to run the Python script using the virtual environment
CMD ["/venv/bin/python", "-u", "counter.py"]
