#include <baobzi_template.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
    double half_length[] = {1.0, 1.0};
    double center[] = {2.0, 2.0};
    baobzi_input_t input;
    input.dim = 2;
    input.output_dim = 1;
    input.order = 8;
    input.data = nullptr;
    input.tol = 1E-10;
    input.func = nullptr;
    input.minimum_leaf_fraction = 0.0;
    input.split_multi_eval = 1;
    input.min_depth = 0;
    input.max_depth = 50;

    auto myfunc = [](const double *x, double *y, const void *) { *y = x[1] * log(x[0]); };

    std::cout << "Testing on 2D function...\n";
    baobzi::Function<2, 8, 0, double> appxfunc(&input, center, half_length, myfunc, {});
    appxfunc.print_stats();

    double val, appx;
    myfunc(center, &val, nullptr);
    appxfunc(center, &appx);
    std::cout << "Error in eval at center: " << val - appx << "\n";

    return 0;
}
