#include "driver_control.hpp"

ULONG driver_control::get_client_base(ULONG process_id, const wchar_t* module_name, size_t module_name_size)
{
    INFO_STRUCT info = { 0 };
    info.code = CODE_CLIENT_REQUEST;
    info.process_id = process_id;
    memcpy(info.module_name, module_name, module_name_size);

    hook::call_hook(&info);

    return info.client_base;
}
