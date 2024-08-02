FROM	ubuntu:20.04

WORKDIR	/app

COPY	..

RUN	apt-get update && apt-get install -y \
	build-essential \
	&& rm -rf /var/lib/apt/lists/*
RUN	make && make clean

CMD	["./fdf"]
