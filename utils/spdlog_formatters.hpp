#pragma once

#include "../logic/game_of_life.hpp"
#include "argparser.hpp"

#include <spdlog/fmt/fmt.h>
#include <sstream>
#include <string>

template<>
struct fmt::formatter<GameOfLife::Rules> {
  auto constexpr parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
    auto it = ctx.begin();
    auto const end = ctx.end();

    if (it != end && *it != '}') {
      throw format_error("Invalid format");
    }

    return it;
  }

  template <typename FormatContext>
  auto format(GameOfLife::Rules const& rules, FormatContext& ctx) -> decltype(ctx.out()) {
    std::stringstream format_stream{};
    for(auto const r: rules.survive) {
      format_stream << r;
    }
    format_stream << '/';
    for(auto const r: rules.revive) {
      format_stream << r;
    }

    return format_to(ctx.out(), format_stream.str());
  }
};

template<>
struct fmt::formatter<Argparser> {
  auto constexpr parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
    auto it = ctx.begin();
    auto const end = ctx.end();

    if (it != end && *it != '}') {
      throw format_error("Invalid format");
    }

    return it;
  }

  template <typename FormatContext>
  auto format(Argparser const& argparser, FormatContext& ctx) -> decltype(ctx.out()) {
    std::stringstream format_stream{};

    if (argparser.arguments_amount() > 0) {
      format_stream << "[";
      for (auto it = argparser.begin(); it != argparser.end() - 1; it++) {
        format_stream << *it << ", ";
      }
      format_stream << *(argparser.end() - 1) << "]";
    } else {
      format_stream << "None";
    }

    return format_to(ctx.out(), format_stream.str());
  }
};
