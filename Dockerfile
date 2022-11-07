FROM epitechcontent/epitest-docker

LABEL title="Epitech R-Type Docker"
LABEL description="Docker image with vcpkg dependencies already compiled for CI/CD purposes"
LABEL maintainer="martin.vanaud@epitech.eu"

WORKDIR /home/r-type/server/

COPY ["Builds/Server/r-type_server", "./"]

EXPOSE 8080
CMD ["./r-type_server", "8080"]
