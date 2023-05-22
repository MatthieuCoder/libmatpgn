FROM debian as build
WORKDIR /app
RUN apt-get update && apt-get install -y build-essential cmake
COPY . .
RUN mkdir build && cd build && cmake .. && make

FROM webdevops/php-nginx:7.4 as server
RUN apt-get update && apt-get install -y texlive-full
COPY www /app
COPY --from=build /app/build/chess2latex/chess2latex /usr/bin/chess2latex
COPY ./render_latex.sh /usr/bin/render_latex.sh
