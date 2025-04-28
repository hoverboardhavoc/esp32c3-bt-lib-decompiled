/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm.o -> llm_hdl_to_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint llm_hdl_to_id(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar1 = (uint)*(byte *)(iVar2 + 0xd);
  switch(param_1) {
  case 0:
    if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
      param_2 = 0xff;
    }
                    /* WARNING: Could not recover jumptable at 0x000109c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(_r_ip_funcs_p + 0x544))(param_2,0,*(code **)(_r_ip_funcs_p + 0x544));
    return uVar1;
  case 1:
    uVar1 = 0;
    while ((iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
           uVar1 < *(byte *)(iVar2 + 0xd) &&
           (2 < (byte)(*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) - 6U)))) {
      uVar1 = uVar1 + 1 & 0xff;
    }
    break;
  case 2:
    uVar1 = 0;
    while ((iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
           uVar1 < *(byte *)(iVar2 + 0xd) &&
           (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) != '\x05'))) {
      uVar1 = uVar1 + 1 & 0xff;
    }
    break;
  case 3:
    uVar1 = param_2 & 0xff;
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((uVar1 < *(byte *)(iVar2 + 0xd)) &&
       (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) != '\t')) {
      iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      uVar1 = (uint)*(byte *)(iVar2 + 0xd);
    }
    break;
  case 4:
    uVar1 = param_2 & 0xff;
  }
  return uVar1;
}

