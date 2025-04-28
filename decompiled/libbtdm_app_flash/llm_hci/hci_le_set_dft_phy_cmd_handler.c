/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  if (((bVar1 & 2) == 0) && (uVar3 = 0x12, param_1[2] == 0)) goto _L12;
  if ((bVar1 & 1) == 0) {
    uVar3 = 0x12;
    if (param_1[1] == 0) goto _L12;
    if ((bVar1 & 2) == 0) goto _L18;
_L19:
    uVar3 = 0x11;
    if (param_1[1] != (param_1[1] & 7)) goto _L12;
    bVar4 = 7;
    if ((bVar1 & 2) == 0) goto _L16;
  }
  else if ((bVar1 & 2) == 0) {
_L18:
    uVar3 = 0x11;
    if (param_1[2] != (param_1[2] & 7)) goto _L12;
    if ((bVar1 & 1) == 0) goto _L19;
_L16:
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
_L12:
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

