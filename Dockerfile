# Stage 1: Build the application
FROM gcc:10.3.0 as builder

# Set the working directory inside the container
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Compile the C++ code using g++ with the C++14 standard
RUN g++ -std=c++14 -o course_planner ProjectTwo.cpp

# Stage 2: Create a smaller final image
FROM alpine:latest

# Install necessary libraries
RUN apk add --no-cache libstdc++ && \
    apk add --no-cache libc6-compat

# Set the working directory inside the container
WORKDIR /app

# Copy the compiled binary from the builder stage
COPY --from=builder /app/course_planner /app/course_planner

# Ensure the binary has execution permissions
RUN chmod +x /app/course_planner

# Specify the command to run the executable when the container starts
CMD ["./course_planner"]
