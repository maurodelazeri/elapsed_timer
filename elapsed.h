//
// Created by mauro on 8/7/19.
//

#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

class Elapsed {
public:
    Elapsed(const std::string &message = "Elapsed time:", bool show_destruction_message = true) :
            m_message(message),
            m_show_destruction_message(show_destruction_message),
            m_t_construct(std::chrono::system_clock::now()) {
    }

    ~Elapsed() {
        if (m_show_destruction_message) {
            const std::string elapsed_time_message = get_elapsed_time_as_string();
            std::cout << std::endl;
            std::cout << "[ " << m_message << " : \t" << elapsed_time_message << " ]" << std::endl;
        }
    }

    std::string get_elapsed_time_as_string() const {
        const auto t_elapsed_in_microsec = get_elapsed_time_in_microseconds();
        const auto t_elapsed_in_millisec = t_elapsed_in_microsec / 1000.0;
        const auto t_elapsed_in_sec = t_elapsed_in_millisec / 1000.0;

        std::ostringstream sstream;
        if (t_elapsed_in_sec > 10.0) {
            sstream << std::fixed << std::setprecision(3) << t_elapsed_in_sec << " s";
        } else if (t_elapsed_in_millisec > 10.0) {
            sstream << std::fixed << std::setprecision(3) << t_elapsed_in_millisec << " ms";
        } else {
            sstream << t_elapsed_in_microsec << " us";
        }
        return sstream.str();
    }

    long get_elapsed_time_in_microseconds() const {
        const auto t_now = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(t_now - m_t_construct).count();
    }

    long get_elapsed_time_in_milliseconds() const {
        const auto t_now = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(t_now - m_t_construct).count();
    }

private:
    const std::string m_message;
    const bool m_show_destruction_message;
    const std::chrono::system_clock::time_point m_t_construct;
};
