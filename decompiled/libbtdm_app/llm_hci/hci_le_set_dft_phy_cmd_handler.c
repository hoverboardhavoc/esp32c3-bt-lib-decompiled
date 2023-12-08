/*
 * Last changed at upstream commit bb9f0f59db474924c9288ab92aed1abb88bc9419
 * https://github.com/espressif/esp32c3-bt-lib/commit/bb9f0f59db474924c9288ab92aed1abb88bc9419
 * Upstream date: 2023-12-08 13:35:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(65db61f)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_set_dft_phy_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_dft_phy_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  
  iVar2 = _p_llm_env;
  bVar1 = *param_1;
  if (((bVar1 & 2) == 0) && (uVar3 = 0x12, param_1[2] == 0)) goto _L87;
  if ((bVar1 & 1) == 0) {
    uVar3 = 0x12;
    if (param_1[1] == 0) goto _L87;
    if ((bVar1 & 2) == 0) goto _L93;
_L94:
    uVar3 = 0x11;
    if (param_1[1] != (param_1[1] & 7)) goto _L87;
    bVar4 = 7;
    if ((bVar1 & 2) == 0) goto _L91;
  }
  else if ((bVar1 & 2) == 0) {
_L93:
    uVar3 = 0x11;
    if (param_1[2] != (param_1[2] & 7)) goto _L87;
    if ((bVar1 & 1) == 0) goto _L94;
_L91:
    bVar4 = param_1[2];
  }
  else {
    bVar4 = 7;
  }
  *(byte *)(_p_llm_env + 0xa3) = bVar4;
  bVar4 = 7;
  if ((bVar1 & 1) == 0) {
    bVar4 = param_1[1];
  }
  *(byte *)(iVar2 + 0xa2) = bVar4;
  uVar3 = 0;
_L87:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

