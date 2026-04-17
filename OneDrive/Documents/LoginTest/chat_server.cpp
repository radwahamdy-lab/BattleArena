#pragma once
#include <iostream>
#include <boost/asio.hpp>
#include "json.hpp"

using namespace std;
using namespace boost::asio;
using ip::tcp;
using json = nlohmann::json;

class ChatServer {
public:
    void start() {
        try {

            boost::asio::io_context io_context;

            tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));

            cout << "--- Server is Running on Port 12345 ---" << endl;
            cout << "Waiting for the Qt App to connect..." << endl;

            while (true) {
                tcp::socket socket(io_context);
                acceptor.accept(socket);

                cout << "[System] Client connected!" << endl;

                boost::asio::streambuf buffer;
                boost::asio::read_until(socket, buffer, "\n");

                string data{
                    boost::asio::buffers_begin(buffer.data()),
                    boost::asio::buffers_end(buffer.data())
                };

                json request = json::parse(data);
                cout << "[Client says]: " << request.dump(4) << endl;

                json response;
                response["status"] = "success";
                response["message"] = "Welcome, " + request["username"].get<string>();

                string response_str = response.dump() + "\n";
                boost::asio::write(socket, boost::asio::buffer(response_str));

                cout << "[Server]: Sent welcome message back." << endl;
            }
        } catch (exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
};
