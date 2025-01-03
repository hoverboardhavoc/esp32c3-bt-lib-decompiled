/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
  if (((bVar1 & 2) == 0) && (uVar3 = 0x12, param_1[2] == 0)) goto _L85;
  if ((bVar1 & 1) == 0) {
    uVar3 = 0x12;
    if (param_1[1] == 0) goto _L85;
    if ((bVar1 & 2) == 0) goto _L91;
_L92:
    uVar3 = 0x11;
    if (param_1[1] != (param_1[1] & 7)) goto _L85;
    bVar4 = 7;
    if ((bVar1 & 2) == 0) goto _L89;
  }
  else if ((bVar1 & 2) == 0) {
_L91:
    uVar3 = 0x11;
    if (param_1[2] != (param_1[2] & 7)) goto _L85;
    if ((bVar1 & 1) == 0) goto _L92;
_L89:
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
_L85:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

