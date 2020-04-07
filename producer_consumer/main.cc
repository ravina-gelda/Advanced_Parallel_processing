#include "pc.h"

int main( int argc, const char* argv[] ) {
    int max_threads = atoi(argv[1]);

    for (int num_threads = 1; num_threads <= max_threads; num_threads *= 2) {
        int num_ops[num_threads];
        int total_num_ops = 0;
        std::thread c[num_threads];
    
        unsigned int seed  = 0;
        init_partitioned(num_threads);

        auto start = std::chrono::system_clock::now();

        std::thread p(producer4, &seed, num_threads); 
        for (int tid=0; tid < num_threads; tid++) {
            c[tid] = std::thread (consumer4, &num_ops[tid], num_threads, tid);
        }
        p.join();
        for (int tid=0; tid < num_threads; tid++) {
            c[tid].join();
            total_num_ops += num_ops[tid];
        }

        auto end = std::chrono::system_clock::now();

        auto elapsed =
            std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            std::cout << elapsed.count() << "ms. Operations: " << total_num_ops << std::endl;;
    }

    return 0;
}
