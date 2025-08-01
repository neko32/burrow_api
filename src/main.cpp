#include "crow/crow.h"
#include <filesystem>
#include <format>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    crow::SimpleApp webapp;
    cout << filesystem::current_path().string() << endl;

    CROW_ROUTE(webapp, "/cat/<string>")([](string cat_name) {
        crow::mustache::context ctx({
            {"cat_name", cat_name}
        });
        string rendered = format("hello {}", cat_name);
        auto resp = crow::response(200, rendered);
        resp.add_header("Content-Type", "text/html; charset=UTF-8");
        return resp;
    });

    webapp.port(18080).multithreaded().run();

}