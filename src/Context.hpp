/*
 * Copyright (C) 2021 CESNET, https://photonics.cesnet.cz/
 *
 * Written by Václav Kubernát <kubernat@cesnet.cz>
 *
*/
#pragma once

#include <memory>
#include "DataNode.hpp"

struct ly_ctx;

namespace libyang {
enum class SchemaFormat {
    Detect = 0,
    Yang = 1,
    Yin = 3
};

enum class DataFormat {
    Detect = 0,
    XML,
    JSON
};

class Context {
public:
    Context();
    void parseModuleMem(const char* data, const SchemaFormat format);
    DataNode parseDataMem(const char* data, const DataFormat format);
private:
    std::unique_ptr<ly_ctx, void(*)(ly_ctx*)> m_ctx;
};
}
