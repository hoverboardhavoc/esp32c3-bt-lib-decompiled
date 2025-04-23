/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_set_dft_phy_cmd_handler
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
  if (((bVar1 & 2) == 0) && (uVar3 = 0x12, param_1[2] == 0)) goto _L11;
  if ((bVar1 & 1) == 0) {
    uVar3 = 0x12;
    if (param_1[1] == 0) goto _L11;
    if ((bVar1 & 2) == 0) goto _L17;
_L18:
    bVar4 = 7;
    uVar3 = 0x11;
    if (7 < param_1[1]) goto _L11;
    if ((bVar1 & 2) == 0) goto _L15;
  }
  else if ((bVar1 & 2) == 0) {
_L17:
    uVar3 = 0x11;
    if (7 < param_1[2]) goto _L11;
    if ((bVar1 & 1) == 0) goto _L18;
_L15:
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
_L11:
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

