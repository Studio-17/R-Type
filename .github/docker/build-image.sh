#!/bin/bash

# Build your image locally
docker build -t r-type_server .

# Re-tag the image for remote push
docker tag r-type_server martinvanaud/r-type_server:latest

# Push image onto docker hub
docker push martinvanaud/r-type_server:latest
