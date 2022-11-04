# B-CPP-500-PAR-5-1-rtype

This is a quick README.md files for the `r-type_server` image.

This image is for deploying our R-Type server on your machine
It runs inside the container on the port 8080, but you can redirect it while running

## Pulling the image
<hr />
First, pull the image from the docker hub

`[sudo] docker pull martinvanaud/r-type_server:latest`

## Running the container
<hr />
Simply run the container with the r-type_server image using docker cli

`[sudo] docker run -dp 8080:${your-port} r-type_server`

Docker standard's exposing ip is: 172.17.0.2

## User Feedback
<hr />

### Issues
<hr/>
If you have any problems with or questions about this image, please contact us through a [Github Issue](https://github.com/EpitechPromo2025/B-CPP-500-PAR-5-1-rtype-martin.vanaud/issues).


### Contributing
<hr />
You are invited to contribute new features, fixes, or updates, large or small; I'm always thrilled to receive pull requests.
