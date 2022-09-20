#!/bin/bash

# Specify folder where you can find sources, on your local machine
SOURCE_FOLDER=$(pwd)

# Specify destination folder to mount your project into docker
DEST_FOLDER=/home/student

docker run --rm -v "$SOURCE_FOLDER:$DEST_FOLDER" -it epitechcontent/epitest-docker /bin/bash -c 'useradd student && su - student'
