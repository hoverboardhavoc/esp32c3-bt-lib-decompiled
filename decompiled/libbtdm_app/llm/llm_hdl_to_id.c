/*
 * Last changed at upstream commit 70f95a1b6f8f232018b17c687cc819044501774c
 * https://github.com/espressif/esp32c3-bt-lib/commit/70f95a1b6f8f232018b17c687cc819044501774c
 * Upstream date: 2024-04-02 18:59:02 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5274796)
 * Source: libbtdm_app -> llm.o -> llm_hdl_to_id
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
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  switch(param_1) {
  case 0:
    if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
      param_2 = 0xff;
    }
                    /* WARNING: Could not recover jumptable at 0x000109b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(_r_ip_funcs_p + 0x544))(param_2,0);
    return uVar2;
  case 1:
    param_2 = 0;
    while ((iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
           param_2 < *(byte *)(iVar1 + 0xd) &&
           (2 < (byte)(*(char *)(*(int *)(_p_llm_env + 8) + param_2 * 0x44 + 0x40) - 6U)))) {
      param_2 = param_2 + 1 & 0xff;
    }
    break;
  case 2:
    param_2 = 0;
    while ((iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
           param_2 < *(byte *)(iVar1 + 0xd) &&
           (*(char *)(*(int *)(_p_llm_env + 8) + param_2 * 0x44 + 0x40) != '\x05'))) {
      param_2 = param_2 + 1 & 0xff;
    }
    break;
  case 3:
  case 4:
    param_2 = param_2 & 0xff;
    break;
  default:
    param_2 = (uint)*(byte *)(iVar1 + 0xd);
  }
  return param_2;
}

