#include <iostream>
#include <set>
#include <vector>
#include "product.cpp"
#include "order.cpp"
#include "customer.cpp"


class Application {
public:
    std::vector<Order> initOrders() {
    Customer customer = Customer(1, "Yulia", 1);
    Product product1 = Product(1, "Apple", "Fruits", 55.0);
    Product product2 = Product(2, "Orange", "Fruits", 99.0);
    Product product3 = Product(3, "Banana", "Fruits", 79.0);
    std::set<Product> products;
    products.insert(product1);
    products.insert(product2);
    roducts.insert(product3);
        Order order1 = Order(1, 1253567813, 1253567819, "Ordered", customer, products);
    products.insert(product3);
    Order order2 = Order(2, 1253567813, 1253567819, "Ordered", customer, products);
    Order order3 = Order(3, 1253567813, 1253567819, "Ordered", customer, products);
    std::vector<Order> orders;
    orders.push_back(order1);
    orders.push_back(order2);
    orders.push_back(order3);
    return orders;
    }

    double getSum(const std::vector<Order>& orders, time_t startT, time_t endT) {
        double sum = 0.0;
            for (const auto& order : orders) {
                if (order.getOrderDate() > startT && order.getOrderDate() < endT) {
                const std::set<Product>& products = order.getProducts();
                sum += std::accumulate(products.begin(), products.end(), 0.0,
    [](double partialSum, const Product& product) {
            return partialSum + product.getPrice();
        });
    }
}
return sum;

    }

    int run() {
        std::vector<Order> orders = initOrders();
        double sum = getSum(orders, 1253567810, 1253567820); 
        std::cout << sum << std::endl;
        return 0;
    }
};


int main() {
    Application app;
    return app.run();
}
