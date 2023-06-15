FROM gcc:11 as build1
COPY . .
RUN g++ LinkedList.cpp


FROM ubuntu
COPY --from=build1 ./a.out ./a.out
CMD ./a.out

