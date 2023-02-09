#include "benchmark.h"
#include "iphone.h"

float getTimePassed(clock_t start, clock_t end);

void runBenchmarks(BenchmarkBase &structToBenchmark, std::string tag)
{
  clock_t pushBackStart = clock();
  for (int i = 0; i < 50000; i++)
  {
    structToBenchmark.pushBack(IPhone());
  }
  clock_t pushBackEnd = clock();

  float timePassedToPushBack = getTimePassed(pushBackStart, pushBackEnd);

  std::cout << "[" << tag << "]: took " << timePassedToPushBack << "s to push back 20 000 elements" << std::endl;

  clock_t pushFrontStart = clock();
  for (int i = 0; i < 10000; i++)
  {
    structToBenchmark.pushFront(IPhone());
  }
  clock_t pushFrontStartEnd = clock();

  float timePassedToPushFront = getTimePassed(pushFrontStart, pushFrontStartEnd);

  std::cout << "[" << tag << "]: took " << timePassedToPushFront << "s to push front 10 000 elements" << std::endl;

  clock_t getElementsStart = clock();
  for (int i = 0; i < 20000; i++)
  {
    structToBenchmark.get(rand() % structToBenchmark.getSize());
  }
  clock_t getElementsEnd = clock();

  float timePassedToGetElements = getTimePassed(getElementsStart, getElementsEnd);

  std::cout << "[" << tag << "]: took " << timePassedToGetElements << "s to get 20 000 elements with random indexes" << std::endl;

  clock_t popFrontStart = clock();
  for (int i = 0; i < 5000; i++)
  {
    structToBenchmark.popFront();
  }
  clock_t popFrontEnd = clock();

  float timePassedToPopFront = getTimePassed(popFrontStart, popFrontEnd);

  std::cout << "[" << tag << "]: took " << timePassedToPopFront << "s to pop front 5 000 elements" << std::endl;

  clock_t popBackStart = clock();
  for (int i = 0; i < 5000; i++)
  {
    structToBenchmark.popBack();
  }
  clock_t popBackEnd = clock();

  float timePassedToPopBack = getTimePassed(popBackStart, popBackEnd);

  std::cout << "[" << tag << "]: took " << timePassedToPopBack << "s to pop back 5 000 elements" << std::endl;

  float totalTimePassed = timePassedToPushBack + timePassedToPushFront + timePassedToGetElements + timePassedToPopFront + timePassedToPopBack;

  std::cout << "[" << tag << "]: took " << totalTimePassed << "s to perform all operations" << std::endl;
}

float getTimePassed(clock_t start, clock_t end)
{
  return ((float)(end - start)) / CLOCKS_PER_SEC;
}