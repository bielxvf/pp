#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace subcmd {

    class option {
    public:
        option();
        option(const std::string& id, const std::string& s, const std::string& l, const std::string& usage, const std::string& params) { m_id = id; m_s = s; m_l = l; m_usage = usage; m_params = params; }

        void setId(const std::string& id) { m_id = id; }
        void setShort(const std::string& s) { m_s = s; }
        void setLong(const std::string& l) { m_l = l; }
        void setUsage(const std::string& usage) { m_usage = usage; }
        void setParams(const std::string& params) { m_params = params; }

        std::string getId() const { return m_id; }
        std::string getShort() const { return m_s; }
        std::string getLong() const { return m_l; }
        std::string getUsage() const { return m_usage; }
        std::string getParams() const { return m_params; }

    private:
        std::string m_id;
        std::string m_s;
        std::string m_l;
        std::string m_usage;
        std::string m_params;
    };
    
}

std::ostream& operator<<(std::ostream& os, const subcmd::option& op)
{
    os << op.getShort() << ", " << op.getLong() << " " << op.getParams() << "\t" << op.getUsage();
    return os;
}


namespace subcmd {

    class program {
    public:
        program(const std::string& id) { m_id = id; }

        void optionAdd(const subcmd::option& option)
        {
            m_options.push_back(option);
        }

        void printHelp()
        {
            std::cout << m_id << " subcommands:" << std::endl;
            for (auto& op: m_options) {
                std::cout << "\t" << op << std::endl;
            }
        }

    private:
        std::vector<subcmd::option> m_options;
        std::string m_id;
    };

}
