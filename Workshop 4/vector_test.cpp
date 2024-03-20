#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

#include "vector_ops.hpp"

TEST_CASE("Mean of a vector is computed", "[mean]") {
    SECTION("Empty vector returns 0.0") {
        std::vector<double> empty_vector;
        REQUIRE(mean(empty_vector) == Approx(0.0).margin(1.0e-3));
    }

    SECTION("Vector filled with same numbers returns that number as mean") {
        std::vector<double> same_number_vector(20, 10.0);
        REQUIRE(mean(same_number_vector) == Approx(10.0).margin(1.0e-3));
    }

    // Caso de prueba: el promedio de un vector dado debe ser calculado correctamente
    SECTION("Mean of {10.0, 15.0, 20.0, 25.0, 30.0} is computed correctly") {
        std::vector<double> test_vector = {10.0, 15.0, 20.0, 25.0, 30.0};
        REQUIRE(mean(test_vector) == Approx(20.0).margin(1.0e-3));
    }

    // Caso de prueba: el promedio de un vector con números decimales debe ser calculado correctamente
    SECTION("Mean of {5.1, 5.2, 5.3, 5.4, 5.5} is computed correctly") {
        std::vector<double> test_vector = {5.1, 5.2, 5.3, 5.4, 5.5};
        REQUIRE(mean(test_vector) == Approx(5.3).margin(1.0e-3));
    }

    // Caso de prueba: el promedio de un vector grande con números enteros debe ser calculado correctamente
    SECTION("Mean of {11.0, 12.0, 13.0, 14.0, 15.0} is computed correctly") {
        std::vector<double> test_vector = {11.0, 12.0, 13.0, 14.0, 15.0};
        REQUIRE(mean(test_vector) == Approx(13.0).margin(1.0e-3));
    }

    // Caso de prueba: el promedio de un vector con incrementos regulares debe ser calculado correctamente
    SECTION("Mean of {3.91, 3.92, ..., 4.00} is computed correctly") {
        std::vector<double> test_vector(10);
        double offset = 3.9;
        for (int i = 0; i < 10; ++i) {
            test_vector[i] = offset + (i + 1) * 0.01;
        }
        REQUIRE(mean(test_vector) == Approx(3.955).margin(1.0e-3));
    }
}