#pragma once

#include <string>
#include <stdint.h>

struct Options
{
  uint16_t port;
  int length;
  int number;
  bool transmit, receive, nodelay;
  std::string host;
  Options()
    : port(0), length(0), number(0),
      transmit(false), receive(false), nodelay(false)
  {
  }
};

bool parseCommandLine(int argc, char* argv[], Options* opt);
struct sockaddr_in resolveOrDie(const char* host, uint16_t port);

struct SessionMessage
{
  int32_t number;
  int32_t length;
} __attribute__ ((__packed__));// __attribute__((__packed__))是编译器指令，告诉它取消结构在编译过程中的优化对齐，按照实际占用的字节数进行对齐

struct PayloadMessage
{
  int32_t length;
  char data[0];
};

void transmit(const Options& opt);

void receive(const Options& opt);
