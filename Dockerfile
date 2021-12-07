FROM ubuntu
RUN apt update 
RUN apt install g++ -qy
COPY copy_file.cpp .
COPY copy_directory.cpp .
RUN g++ copy_file.cpp -o copy_file
RUN g++ copy_directory.cpp -o copy_directory
CMD ./copy_directory /etc /home && ls /home
