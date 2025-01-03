/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_set_priv_mode_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_priv_mode_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(_p_llm_env + 0xc6) != '\0') {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x504))(*(code **)(_r_ip_funcs_p + 0x504));
    uVar2 = 0xc;
    if (iVar1 != 0) goto _L69;
  }
  uVar2 = 0x12;
  if (param_1[7] < 2) {
    uVar2 = 0x12;
    if (*param_1 < 2) {
      uVar2 = (**(code **)(_r_ip_funcs_p + 0x28c))(param_1 + 1,*(code **)(_r_ip_funcs_p + 0x28c));
    }
  }
_L69:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

