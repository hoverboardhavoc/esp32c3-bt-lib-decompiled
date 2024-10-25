/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm.o -> llm_hdl_to_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint llm_hdl_to_id(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = r_sdk_config_get_opts();
  switch(param_1) {
  case 0:
    if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
      param_2 = 0xff;
    }
    uVar2 = r_llm_adv_hdl_to_id(param_2,0);
    return uVar2;
  case 1:
    param_2 = 0;
    while ((iVar1 = r_sdk_config_get_opts(), param_2 < *(byte *)(iVar1 + 0xd) &&
           (2 < (byte)(*(char *)(*(int *)(_p_llm_env + 8) + param_2 * 0x44 + 0x40) - 6U)))) {
      param_2 = param_2 + 1 & 0xff;
    }
    break;
  case 2:
    param_2 = 0;
    while ((iVar1 = r_sdk_config_get_opts(), param_2 < *(byte *)(iVar1 + 0xd) &&
           (*(char *)(*(int *)(_p_llm_env + 8) + param_2 * 0x44 + 0x40) != '\x05'))) {
      param_2 = param_2 + 1 & 0xff;
    }
    break;
  case 3:
    iVar1 = r_sdk_config_get_opts();
    param_2 = param_2 & 0xff;
    if (*(byte *)(iVar1 + 0xd) <= param_2) {
      return param_2;
    }
    if (*(char *)(*(int *)(_p_llm_env + 8) + param_2 * 0x44 + 0x40) == '\t') {
      return param_2;
    }
    iVar1 = r_sdk_config_get_opts();
  default:
    param_2 = (uint)*(byte *)(iVar1 + 0xd);
    break;
  case 4:
    param_2 = param_2 & 0xff;
  }
  return param_2;
}

