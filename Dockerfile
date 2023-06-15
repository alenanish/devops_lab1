FROM gcc:11 as build
COPY . .
RUN g++ Main.cpp LinkedList.cpp


FROM ubuntu
COPY --from=build ./a.out ./a.out
CMD ./a.out

