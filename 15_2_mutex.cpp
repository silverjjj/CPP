/*
#include <iostream>
#include <mutex>  // mutex �� ����ϱ� ���� �ʿ�
#include <thread>
#include <vector>

void worker(int& result, std::mutex& m) {
  for (int i = 0; i < 10000; i++) {
    m.lock();       // mutex�� lock �ؼ�, �ϳ��� �����忡���� ����� �� ����
    result += 1;
    m.unlock();     // mutex ��ȯ
  }
}

int main() {
  int counter = 0;
  std::mutex m;  // �츮�� mutex ��ü

  std::vector<std::thread> workers;
  for (int i = 0; i < 4; i++) {
    // mutex�� �� �����忡�� ����ϱ� ���� ����
    workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
  }

  for (int i = 0; i < 4; i++) {
    workers[i].join();
  }

  std::cout << "Counter ���� �� : " << counter << std::endl;
}
*/

/*
#include <iostream>
#include <mutex>  // mutex �� ����ϱ� ���� �ʿ�
#include <thread>
#include <vector>

void worker(int& result, std::mutex& m) {
  for (int i = 0; i < 10000; i++) {
    // lock ���� �ÿ� m.lock() �� �����Ѵٰ� ���� �ȴ�.
    std::lock_guard<std::mutex> lock(m);
    result += 1;

    // scope �� ���� ������ lock �� �Ҹ�Ǹ鼭
    // m �� �˾Ƽ� unlock �Ѵ�.
  }
}

int main() {
  int counter = 0;
  std::mutex m;  // �츮�� mutex ��ü

  std::vector<std::thread> workers;
  for (int i = 0; i < 4; i++) {
    workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
  }

  for (int i = 0; i < 4; i++) {
    workers[i].join();
  }

  std::cout << "Counter ���� �� : " << counter << std::endl;
}
*/


/*


#include <chrono>  // std::chrono::miliseconds
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

void producer(std::queue<std::string>* downloaded_pages, std::mutex* m,
              int index) {
  for (int i = 0; i < 5; i++) {
    // ������Ʈ�� �ٿ�ε� �ϴµ� �ɸ��� �ð��̶� �����ϸ� �ȴ�.
    // �� ������ ���� �ٿ�ε� �ϴµ� �ɸ��� �ð��� �ٸ���.
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
    std::string content = "������Ʈ : " + std::to_string(i) + " from thread(" +
                          std::to_string(index) + ")\n";

    // data �� ������ ���̿��� �����ǹǷ� critical section �� �־�� �Ѵ�.
    m->lock();
    downloaded_pages->push(content);
    m->unlock();
  }
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m,
              int* num_processed) {
  // ��ü ó���ϴ� ������ ������ 5 * 5 = 25 ��.
  while (*num_processed < 25) {
    m->lock();
    // ���� ���� �ٿ�ε��� �������� ���ٸ� �ٽ� ���.
    if (downloaded_pages->empty()) {
      m->unlock();  // (Quiz) ���⼭ unlock �� ���Ѵٸ� ��� �ɱ��?

      // 10 �и��� �ڿ� �ٽ� Ȯ���Ѵ�.
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
      continue;
    }

    // �� ���� �������� �а� ��� ��Ͽ��� �����Ѵ�.
    std::string content = downloaded_pages->front();
    downloaded_pages->pop();

    (*num_processed)++;
    m->unlock();

    // content �� ó���Ѵ�.
    std::cout << content;
    std::this_thread::sleep_for(std::chrono::milliseconds(80));
  }
}

int main() {
  // ���� �ٿ�ε��� �������� ����Ʈ��, ���� ó������ ���� �͵��̴�.
  std::queue<std::string> downloaded_pages;
  std::mutex m;

  std::vector<std::thread> producers;
  for (int i = 0; i < 5; i++) {
    producers.push_back(std::thread(producer, &downloaded_pages, &m, i + 1));
  }

  int num_processed = 0;
  std::vector<std::thread> consumers;
  for (int i = 0; i < 3; i++) {
    consumers.push_back(
        std::thread(consumer, &downloaded_pages, &m, &num_processed));
  }

  for (int i = 0; i < 5; i++) {
    producers[i].join();
  }
  for (int i = 0; i < 3; i++) {
    consumers[i].join();
  }
}
*/


#include <chrono>              // std::chrono::miliseconds
#include <condition_variable>  // std::condition_variable
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

void producer(std::queue<std::string>* downloaded_pages, std::mutex* m,
              int index, std::condition_variable* cv) {
  for (int i = 0; i < 5; i++) {
    // ������Ʈ�� �ٿ�ε� �ϴµ� �ɸ��� �ð��̶� �����ϸ� �ȴ�.
    // �� ������ ���� �ٿ�ε� �ϴµ� �ɸ��� �ð��� �ٸ���.
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
    std::string content = "������Ʈ : " + std::to_string(i) + " from thread(" +
                          std::to_string(index) + ")\n";

    // data �� ������ ���̿��� �����ǹǷ� critical section �� �־�� �Ѵ�.
    m->lock();
    downloaded_pages->push(content);
    m->unlock();

    // consumer ���� content �� �غ�Ǿ����� �˸���.
    cv->notify_one();
  }
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m,
              int* num_processed, std::condition_variable* cv) {
  while (*num_processed < 25) {
    std::unique_lock<std::mutex> lk(*m);

    cv->wait(lk, [&] { return !downloaded_pages->empty() || *num_processed == 25; });

    if (*num_processed == 25) {     // ��� ������ ó���� �Ϸ��ߴٸ� Ż��
      lk.unlock();
      return;
    }

    // �� ���� �������� �а� ��� ��Ͽ��� �����Ѵ�.
    std::string content = downloaded_pages->front();
    downloaded_pages->pop();

    (*num_processed)++;
    lk.unlock();

    // content �� ó���Ѵ�.
    std::cout << content;
    std::this_thread::sleep_for(std::chrono::milliseconds(80));
  }
}

int main() {
  // ���� �ٿ�ε��� �������� ����Ʈ��, ���� ó������ ���� �͵��̴�.
  std::queue<std::string> downloaded_pages;
  std::mutex m;
  std::condition_variable cv;

  std::vector<std::thread> producers;
  for (int i = 0; i < 5; i++) {
    producers.push_back(
        std::thread(producer, &downloaded_pages, &m, i + 1, &cv));
  }

  int num_processed = 0;
  std::vector<std::thread> consumers;
  for (int i = 0; i < 3; i++) {
    consumers.push_back(
        std::thread(consumer, &downloaded_pages, &m, &num_processed, &cv));
  }
  
  for (int i = 0; i < 5; i++) {
    producers[i].join();
  }

  // ������ �ڰ� �ִ� ��������� ��� �����.
  cv.notify_all();

  for (int i = 0; i < 3; i++) {
    consumers[i].join();
  }
}


